#include <assert.h>
#include <fcntl.h>
#include <regex.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

struct AST {
  char *ast_type;      // 生成規則を区別
  struct AST *parent;  // 親へのバックポインタ
  int nth;             // 自分が何番目の兄弟か
  int num_child;       // 子ノードの数
  struct AST **child;  // 子ノードポインタの配列
  char *lexeme;        // 葉ノード用 (整数，文字，文字列の定数，識別子）
};

/* ------------------------------------------------------- */
static void print_nspace(int n);
static struct AST *create_AST(char *ast_type, int num_child, ...);
static struct AST *create_leaf(char *ast_type, char *lexeme);
static struct AST *add_AST(struct AST *ast, int num_child, ...);
static void show_AST(struct AST *ast, int depth);
static void unparse_AST(struct AST *ast, int depth);

static struct AST *parse_translation_unit(void);

static char *map_file(char *filename);
static void my_regcomp(regex_t *regex_p, char *pattern);
static int my_regexec(regex_t *regex_p, char *str, regmatch_t *regmatch_p);
static void *copy_string_region_int(char *s, int start, int end);
static void *copy_string_region_ptr(char *start, char *end);
static void *copy_string_region_regmatch(char *s, regmatch_t *regmatch_p);
static int skip_block_comment(char *ptr, int off);
static int skip_whitespaces(char *ptr, int off);
static int strncmp_r(char *s1, char *s2);
static int check_kind_id(char *lexeme);
static int set_token_int(char *ptr, int begin, int end, int kind, int off);
static int set_token_regmatch(char *ptr, regmatch_t *regmatch_p, int kind,
                              int off);
static void create_tokens(char *ptr);
static void dump_tokens();
/* ------------------------------------------------------- */
// データ構造と変数

#define MAX_TOKENS 10000
struct token {
  int kind;
  int offset_begin;
  int offset_end;
  char *lexeme;
};
enum token_kind {
  TK_UNUSED = 0,
  TK_ID = 1,
  TK_INT = 2,
  TK_CHAR = 3,
  TK_STRING = 4,
  TK_KW_CHAR = 5,      // char
  TK_KW_ELSE = 6,      // else
  TK_KW_GOTO = 7,      // goto
  TK_KW_IF = 8,        // if
  TK_KW_INT = 9,       // int
  TK_KW_RETURN = 10,   // return
  TK_KW_VOID = 11,     // void
  TK_KW_WHILE = 12,    // while
  TK_OP_EQ = 13,       // ==
  TK_OP_AND = 14,      // &&
  TK_OP_OR = 15,       // ||
  TK_KW_LONG = 16,     // long
  TK_COMMENT = 17,     // デバッグ用
  TK_WHITESPACE = 18,  // デバッグ用
                       // 以下は名前を付けずにそのまま使う
  // ';' ':' '{' '}' ',' '=' '(' ')' '&' '!' '-' '+' '*' '/' '<'
};

char *token_kind_string[] = {
    "UNUSED",    "ID",        "INT",       "CHAR",      "STRING",
    "char",      "else",      "goto",      "if",        "int",
    "return",    "void",      "while",     "==",        "&&",
    "||",        "long",      [';'] = ";", [':'] = ":", ['{'] = "{",
    ['}'] = "}", [','] = ",", ['='] = "=", ['('] = "(", [')'] = ")",
    ['&'] = "&", ['!'] = "!", ['-'] = "-", ['+'] = "+", ['*'] = "*",
    ['/'] = "/", ['<'] = "<",
};

enum grammar_constructs_kind {
  CK_UNUSED = 0,
  CK_TRANSLATION_UNIT = 1,
  CK_TYPE_SPECIFIER = 2,
  CK_DECLARATOR = 3,
  CK_PARAMETER_DECLARATION = 4,
  CK_STATEMENT = 5,
  CK_COMPOUND_STATEMENT = 6,
  CK_EXPRESSION = 7,
  CK_UNARY_OPERATOR = 8,
  CK_BINARY_OPERATOR = 9,
  CK_ARGUMENT_EXPRESSION_LIST = 10,
};

char *grammar_constructs_kind_string[] = {"unused",
                                          "translation_unit",
                                          "type_specifier",
                                          "declarator",
                                          "parameter_declaration",
                                          "statement",
                                          "compound_statement",
                                          "expression",
                                          "unary_operator",
                                          "binary_operator",
                                          "argument_expression_list"};

static struct token tokens[MAX_TOKENS];
static int tokens_index = 0;
static struct token *token_p;  // for parsing

/* ------------------------------------------------------- */
static void print_nspace(int n) { printf("%*s", n, ""); }

static void printf_ns(int n, const char *format, ...) {
  va_list arg;
  print_nspace(n * 4);  // 空文字列をn*4幅で印字
  va_start(arg, format);
  vprintf(format, arg);
  va_end(arg);
}

static struct AST *create_AST(char *ast_type, int num_child, ...) {
  va_list ap;
  struct AST *ast;
  ast = malloc(sizeof(struct AST));
  ast->parent = NULL;
  ast->nth = -1;
  ast->ast_type = ast_type;
  ast->num_child = num_child;
  ast->lexeme = NULL;
  va_start(ap, num_child);
  if (num_child == 0) {
    ast->child = NULL;
  } else {
    int i;
    ast->child = malloc(sizeof(struct AST *) * num_child);
    for (i = 0; i < num_child; i++) {
      struct AST *child = va_arg(ap, struct AST *);
      ast->child[i] = child;
      if (child != NULL) {
        child->parent = ast;
        child->nth = i;
      }
    }
  }
  va_end(ap);
  return ast;
}

static struct AST *create_leaf(char *ast_type, char *lexeme) {
  struct AST *ast;
  ast = malloc(sizeof(struct AST));
  ast->parent = NULL;
  ast->nth = -1;
  ast->ast_type = ast_type;
  ast->num_child = 0;
  ast->child = NULL;
  ast->lexeme = lexeme;
  return ast;
}

static struct AST *add_AST(struct AST *ast, int num_child, ...) {
  va_list ap;
  int i, start = ast->num_child;
  ast->num_child += num_child;
  assert(num_child > 0);
  ast->child = realloc(ast->child, sizeof(struct AST *) * ast->num_child);
  va_start(ap, num_child);
  for (i = start; i < ast->num_child; i++) {
    struct AST *child = va_arg(ap, struct AST *);
    ast->child[i] = child;
    if (child != NULL) {
      child->parent = ast;
      child->nth = i;
    }
  }
  va_end(ap);
  return ast;
}

static void show_AST(struct AST *ast, int depth) {
  int i;
  print_nspace(depth);
  if (!strcmp(ast->ast_type, "ID") || !strcmp(ast->ast_type, "INT") ||
      !strcmp(ast->ast_type, "CHAR") || !strcmp(ast->ast_type, "STRING")) {
    printf("%s (%s)\n", ast->ast_type, ast->lexeme);
  } else {
    printf("%s\n", ast->ast_type);
  }

  for (i = 0; i < ast->num_child; i++) {
    if (ast->child[i] != NULL) {
      show_AST(ast->child[i], depth + 1);
    }
  }
}
/* ------------------------------------------------------- */
// 構文解析

static void parse_error(void) {
  fprintf(stderr, "parse error (%d-%d): %s (%s)\n", token_p->offset_begin,
          token_p->offset_end, token_kind_string[token_p->kind],
          token_p->lexeme);
  exit(1);
}

static int lookahead(int i) { return tokens[tokens_index + i - 1].kind; }

static struct token *next_token(void) {
  token_p = &tokens[++tokens_index];
  assert(tokens_index < MAX_TOKENS);
  return token_p;
}

static struct token *reset_tokens(void) {
  tokens_index = 0;
  token_p = &tokens[tokens_index];
  return token_p;
}

static void consume_token(enum token_kind kind) {
  if (lookahead(1) == kind) {
    next_token();
  } else {
    parse_error();
  }
}

static struct AST *create_construct_AST(enum grammar_constructs_kind kind) {
  struct AST *ast = create_AST(grammar_constructs_kind_string[kind], 0);
  return ast;
}

static struct AST *create_final_word(enum token_kind kind) {
  struct AST *ast = create_leaf(token_kind_string[kind], token_p->lexeme);
  consume_token(kind);
  return ast;
}

static struct AST *parse_translation_unit(void);
static struct AST *parse_type_specifier(void);
static struct AST *parse_declarator(void);
static struct AST *parse_parameter_declaration(void);
static struct AST *parse_statement(void);
static struct AST *parse_compound_statement(void);
static struct AST *parse_expression(void);
static struct AST *parse_unary_operator(void);
static struct AST *parse_binary_operator(void);
static struct AST *parse_argument_expression_list(void);

static struct AST *parse_type_specifier(void) {
  struct AST *ast, *ast1;
  ast = create_construct_AST(CK_TYPE_SPECIFIER);
  switch (lookahead(1)) {
    case TK_KW_INT:
    case TK_KW_LONG:
    case TK_KW_CHAR:
    case TK_KW_VOID:
      ast1 = create_final_word(lookahead(1));
      ast = add_AST(ast, 1, ast1);
      break;
    default:
      parse_error();
      break;
  }
  return ast;
}

static struct AST *parse_declarator(void) {
  struct AST *ast, *ast1, *ast2, *ast3, *dec;
  ast = create_construct_AST(CK_DECLARATOR);

  switch (lookahead(1)) {
    case TK_ID:
      ast1 = create_final_word(TK_ID);
      ast = add_AST(ast, 1, ast1);
      break;
    case '*':
      ast1 = create_final_word('*');
      ast2 = parse_declarator();
      ast = add_AST(ast, 2, ast1, ast2);
      break;
    case '(':
      ast1 = create_final_word('(');
      ast2 = parse_declarator();
      ast3 = create_final_word(')');
      ast = add_AST(ast, 3, ast1, ast2, ast3);
      break;
    default:
      parse_error();
      break;
  }

  dec = create_construct_AST(CK_DECLARATOR);
  while (lookahead(1) == '(') {
    ast1 = create_final_word('(');
    dec = add_AST(dec, 2, ast, ast1);

    switch (lookahead(1)) {
      case TK_KW_VOID:
      case TK_KW_CHAR:
      case TK_KW_INT:
      case TK_KW_LONG:
        ast1 = parse_parameter_declaration();
        dec = add_AST(dec, 1, ast1);

        while (lookahead(1) == ',') {
          ast1 = create_final_word(',');
          ast2 = parse_parameter_declaration();
          dec = add_AST(dec, 2, ast1, ast2);
        }
        break;
      default:
        break;
    }

    ast1 = create_final_word(')');
    dec = add_AST(dec, 1, ast1);
    ast = dec;
  }

  return ast;
}

static struct AST *parse_parameter_declaration(void) {
  struct AST *ast, *ast1, *ast2;
  ast = create_construct_AST(CK_PARAMETER_DECLARATION);
  ast1 = parse_type_specifier();
  ast2 = parse_declarator();
  ast = add_AST(ast, 2, ast1, ast2);
  return ast;
}

static struct AST *parse_compound_statement(void) {
  struct AST *ast, *ast1, *ast2, *ast3;
  ast = create_construct_AST(CK_COMPOUND_STATEMENT);
  ast1 = create_final_word('{');
  ast = add_AST(ast, 1, ast1);

  while (1) {
    switch (lookahead(1)) {
      case TK_KW_INT:
      case TK_KW_LONG:
      case TK_KW_CHAR:
      case TK_KW_VOID:
        ast1 = parse_type_specifier();
        ast2 = parse_declarator();
        ast3 = create_final_word(';');
        ast = add_AST(ast, 3, ast1, ast2, ast3);
        break;
      default:
        goto loop_exit;
    }
  }
loop_exit:

  while (1) {
    switch (lookahead(1)) {
      case '{':
      case TK_KW_IF:
      case TK_KW_WHILE:
      case TK_KW_GOTO:
      case TK_KW_RETURN:
      case ';':
      case TK_INT:
      case TK_CHAR:
      case TK_STRING:
      case TK_ID:
      case '(':
      case '&':
      case '*':
      case '+':
      case '-':
      case '!':
        ast1 = parse_statement();
        ast = add_AST(ast, 1, ast1);
        break;
      default:
        goto state_loop_exit;
    }
  }
state_loop_exit:

  ast1 = create_final_word('}');
  ast = add_AST(ast, 1, ast1);

  return ast;
}

static struct AST *parse_expression(void) {
  struct AST *ast, *ast1, *ast2, *ast3, *exp;
  ast = create_construct_AST(CK_EXPRESSION);

  switch (lookahead(1)) {
    case TK_ID:
    case TK_INT:
    case TK_CHAR:
    case TK_STRING:
      ast1 = create_final_word(lookahead(1));
      ast = add_AST(ast, 1, ast1);
      break;
    case '&':
    case '*':
    case '+':
    case '-':
    case '!':
      ast1 = parse_unary_operator();
      ast2 = parse_expression();
      ast = add_AST(ast, 2, ast1, ast2);
      break;
    case '(':
      ast1 = create_final_word('(');
      ast2 = parse_expression();
      ast3 = create_final_word(')');
      ast = add_AST(ast, 3, ast1, ast2, ast3);
      break;
    default:
      parse_error();
  }

  exp = create_construct_AST(CK_EXPRESSION);
  while (1) {
    switch (lookahead(1)) {
      case '=':
      case TK_OP_OR:
      case TK_OP_AND:
      case TK_OP_EQ:
      case '<':
      case '+':
      case '-':
      case '*':
      case '/':

        ast1 = parse_binary_operator();
        ast2 = parse_expression();
        exp = add_AST(exp, 3, ast, ast1, ast2);
        ast = exp;
        break;
      case '(':
        ast1 = create_final_word('(');
        exp = add_AST(exp, 2, ast, ast1);
        switch (lookahead(1)) {
          case TK_ID:
          case TK_INT:
          case TK_CHAR:
          case TK_STRING:
          case '&':
          case '*':
          case '+':
          case '-':
          case '!':
          case '(':
            ast1 = parse_argument_expression_list();
            exp = add_AST(exp, 1, ast1);
            break;
          default:
            break;
        }
        ast1 = create_final_word(')');
        exp = add_AST(exp, 1, ast1);
        ast = exp;
        break;
      default:
        goto loop_exit;
    }
  }

loop_exit:

  return ast;
}

static struct AST *parse_statement(void) {
  struct AST *ast, *ast1, *ast2, *ast3, *ast4, *ast5;
  ast = create_construct_AST(CK_STATEMENT);

  if (lookahead(1) == TK_ID && lookahead(2) == ':') {
    ast1 = create_final_word(TK_ID);
    ast2 = create_final_word(':');
    ast = add_AST(ast, 2, ast1, ast2);
    return ast;
  }

  switch (lookahead(1)) {
    case '{':
      ast1 = parse_compound_statement();
      ast = add_AST(ast, 1, ast1);
      break;
    case TK_KW_IF:
      ast1 = create_final_word(TK_KW_IF);
      ast2 = create_final_word('(');
      ast3 = parse_expression();
      ast4 = create_final_word(')');
      ast5 = parse_statement();

      ast = add_AST(ast, 5, ast1, ast2, ast3, ast4, ast5);

      if (lookahead(1) == TK_KW_ELSE) {
        ast1 = create_final_word(TK_KW_ELSE);
        ast2 = parse_statement();
        ast = add_AST(ast, 2, ast1, ast2);
      }
      break;
    case TK_KW_WHILE:
      ast1 = create_final_word(TK_KW_WHILE);
      ast2 = create_final_word('(');
      ast3 = parse_expression();
      ast4 = create_final_word(')');
      ast5 = parse_statement();
      ast = add_AST(ast, 5, ast1, ast2, ast3, ast4, ast5);
      break;
    case TK_KW_GOTO:
      ast1 = create_final_word(TK_KW_GOTO);
      if (lookahead(1) != TK_ID) parse_error();
      ast2 = create_final_word(TK_ID);
      ast3 = create_final_word(';');
      ast = add_AST(ast, 3, ast1, ast2, ast3);
      break;
    case TK_KW_RETURN:
      ast1 = create_final_word(TK_KW_RETURN);
      ast = add_AST(ast, 1, ast1);
      switch (lookahead(1)) {
        case TK_ID:
        case TK_INT:
        case TK_CHAR:
        case TK_STRING:
        case '&':
        case '*':
        case '+':
        case '-':
        case '!':
        case '(':
          ast1 = parse_expression();
          ast = add_AST(ast, 1, ast1);
          break;
        default:
          break;
      }
      ast1 = create_final_word(';');
      ast = add_AST(ast, 1, ast1);
      break;
    case TK_ID:
    case TK_INT:
    case TK_CHAR:
    case TK_STRING:
    case '&':
    case '*':
    case '+':
    case '-':
    case '!':
    case '(':
      ast1 = parse_expression();
      ast2 = create_final_word(';');
      ast = add_AST(ast, 2, ast1, ast2);
      break;
    case ';':
      ast1 = create_final_word(';');
      ast = add_AST(ast, 1, ast1);
      break;
    default:
      parse_error();
  }

  return ast;
}

static struct AST *parse_unary_operator(void) {
  struct AST *ast, *ast1;

  ast = create_construct_AST(CK_UNARY_OPERATOR);
  switch (lookahead(1)) {
    case '&':
    case '*':
    case '+':
    case '-':
    case '!':
      ast1 = create_final_word(lookahead(1));
      ast = add_AST(ast, 1, ast1);
      break;
    default:
      parse_error();
  }

  return ast;
}

static struct AST *parse_binary_operator(void) {
  struct AST *ast, *ast1;

  ast = create_construct_AST(CK_BINARY_OPERATOR);
  switch (lookahead(1)) {
    case '=':
    case TK_OP_OR:
    case TK_OP_AND:
    case TK_OP_EQ:
    case '<':
    case '+':
    case '-':
    case '*':
    case '/':
      ast1 = create_final_word(lookahead(1));
      ast = add_AST(ast, 1, ast1);
      break;
    default:
      parse_error();
  }

  return ast;
}

static struct AST *parse_argument_expression_list(void) {
  struct AST *ast, *ast1, *ast2;

  ast = create_construct_AST(CK_ARGUMENT_EXPRESSION_LIST);
  ast1 = parse_expression();
  ast = add_AST(ast, 1, ast1);

  while (lookahead(1) == ',') {
    ast1 = create_final_word(',');
    ast2 = parse_expression();
    ast = add_AST(ast, 2, ast1, ast2);
  }

  return ast;
}

// translation_unit: ( type_specifier declarator ( ";" | compound_statement ))*
static struct AST *parse_translation_unit(void) {
  struct AST *ast, *ast1, *ast2, *ast3;

  ast = create_construct_AST(CK_TRANSLATION_UNIT);
  while (1) {
    switch (lookahead(1)) {
      case TK_KW_INT:
      case TK_KW_LONG:
      case TK_KW_CHAR:
      case TK_KW_VOID:
        ast1 = parse_type_specifier();
        ast2 = parse_declarator();
        switch (lookahead(1)) {
          case ';':
            consume_token(';');
            ast3 = create_AST(";", 0);
            break;
          case '{':
            ast3 = parse_compound_statement();
            break;
          default:
            parse_error();
            break;
        }
        ast = add_AST(ast, 3, ast1, ast2, ast3);
        break;
      default:
        goto loop_exit;
    }
  }
loop_exit:
  return ast;
}

/* ------------------------------------------------------- */
// 字句解析

static char *map_file(char *filename) {
  struct stat sbuf;
  char *ptr;

  int fd = open(filename, O_RDWR);
  if (fd == -1) {
    perror("open");
    exit(1);
  }

  fstat(fd, &sbuf);
#if 0
    printf ("file size = %lld\n", sbuf.st_size);
#endif

  ptr = mmap(NULL, sbuf.st_size + 1,  // +1 for '\0'
             PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (ptr == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }
  ptr[sbuf.st_size] = '\0';
  return ptr;
}

static void my_regcomp(regex_t *regex_p, char *pattern) {
  static char buf[BUFSIZ];
  int ret = regcomp(regex_p, pattern, REG_EXTENDED);

  if (ret != 0) {
    regerror(ret, regex_p, buf, sizeof(buf));
    fprintf(stderr, "regcomp: %s\n", buf);
    exit(1);
  }
}

static int my_regexec(regex_t *regex_p, char *str, regmatch_t *regmatch_p) {
  int ret = regexec(regex_p, str, 1, regmatch_p, 0);
#if 0
    if (ret == 0) {
        fprintf (stderr, "matched: |%lld, %lld: %.40s|\n",
                 regmatch_p->rm_so, regmatch_p->rm_eo, str+regmatch_p->rm_so);
    } else {
        fprintf (stderr, "unmatched\n");
    }
#endif
  return ret;
}

static void *copy_string_region_int(char *s, int start, int end) {
  int size = end - start;
  char *buf = malloc(size + 1);  // +1 for '\0'
  memcpy(buf, s + start, size);
  buf[size] = '\0';
  return buf;
}

static void *copy_string_region_ptr(char *start, char *end) {
  int size = end - start;
  char *buf = malloc(size + 1);  // +1 for '\0'
  memcpy(buf, start, size);
  buf[size] = '\0';
  return buf;
}

static void *copy_string_region_regmatch(char *s, regmatch_t *regmatch_p) {
  return copy_string_region_int(s, regmatch_p->rm_so, regmatch_p->rm_eo);
}

static int skip_block_comment(char *ptr, int off) {
  int i = off;

  assert((ptr[i] == '/') && (ptr[i + 1] == '*'));
  i += 2;
  while ((ptr[i] != '\0') && !(ptr[i] == '*' && ptr[i + 1] == '/')) {
    i++;
  }
  if (ptr[i] != '\0') i += 2;

#if 0
    char *buf = copy_string_region_ptr (ptr + off, ptr + i);
    printf ("block_comment(%d-%d)=|%s|\n", off, i, buf);
    set_token_int (ptr, 0, i - off, TK_COMMENT, off);
#endif
  return i;
}

static int skip_whitespaces(char *ptr, int off) {
  int i = off;

  while (ptr[i] != '\0') {
    int c = ptr[i];
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
      i++;
    } else {
      break;
    }
  }
#if 0
    char *buf = copy_string_region_ptr (ptr + off, ptr + i);
    printf ("whitespaces(%d, %d)=|%s|\n", off, i, buf);
    set_token_int (ptr, 0, i - off, TK_WHITESPACE, off);
#endif
  return i;
}

static int strncmp_r(char *s1, char *s2) { return strncmp(s1, s2, strlen(s2)); }

static int check_kind_id(char *lexeme) {
  if (!strcmp(lexeme, "char"))
    return TK_KW_CHAR;
  else if (!strcmp(lexeme, "else"))
    return TK_KW_ELSE;
  else if (!strcmp(lexeme, "goto"))
    return TK_KW_GOTO;
  else if (!strcmp(lexeme, "if"))
    return TK_KW_IF;
  else if (!strcmp(lexeme, "int"))
    return TK_KW_INT;
  else if (!strcmp(lexeme, "long"))
    return TK_KW_LONG;
  else if (!strcmp(lexeme, "return"))
    return TK_KW_RETURN;
  else if (!strcmp(lexeme, "void"))
    return TK_KW_VOID;
  else if (!strcmp(lexeme, "while"))
    return TK_KW_WHILE;
  else
    return TK_ID;
}

static int set_token_int(char *ptr, int begin, int end, int kind, int off) {
  assert(tokens_index < MAX_TOKENS);
  struct token *token_p = &tokens[tokens_index++];
  assert(begin == 0);
  token_p->kind = kind;
  token_p->offset_begin = off + begin;
  token_p->offset_end = off + end;
  token_p->lexeme = copy_string_region_int(ptr + off, begin, end);
#if 0
    printf ("topen_p->lexeme = |%s|\n", token_p->lexeme);
#endif
  return off + end;
}

static int set_token_regmatch(char *ptr, regmatch_t *regmatch_p, int kind,
                              int off) {
  return set_token_int(ptr, regmatch_p->rm_so, regmatch_p->rm_eo, kind, off);
}

static void create_tokens(char *ptr) {
  static char str_id[] = "^[a-zA-Z_][a-zA-Z0-9_]*";
  static char str_int[] = "^(0|[1-9][0-9]*)";
  // regcomp に渡すパターンは ^'(\\n|\\'|\\\\|[^\'])' エスケープすると以下
  static char str_char[] = "^'(\\\\n|\\\\'|\\\\\\\\|[^\\'])'";
  // regcomp に渡すパターンは ^"(\\n|\\"|\\\\|[^\"])*" エスケープすると以下
  static char str_string[] = "^\"(\\\\n|\\\\\"|\\\\\\\\|[^\\\"])*\"";
  static regex_t regex_id, regex_int, regex_char, regex_string;
  static regmatch_t regmatch;

  char *ptr_start = ptr;
  int off = 0;

  my_regcomp(&regex_id, str_id);
  my_regcomp(&regex_int, str_int);
  my_regcomp(&regex_char, str_char);
  my_regcomp(&regex_string, str_string);

  while (ptr[off] != '\0') {
    int ret;

    if ((ptr[off] == '/') && (ptr[off + 1] == '*')) {
      off = skip_block_comment(ptr, off);
      continue;
    } else if (ptr[off] == ' ' || ptr[off] == '\t' || ptr[off] == '\n' ||
               ptr[off] == '\r') {
      off = skip_whitespaces(ptr, off);
      continue;
    }

    ret = my_regexec(&regex_id, ptr + off, &regmatch);
    if (ret == 0) {
      char *lexeme = copy_string_region_regmatch(ptr + off, &regmatch);
      int kind = check_kind_id(lexeme);
      off = set_token_regmatch(ptr, &regmatch, kind, off);
      free(lexeme);
      continue;
    }
    ret = my_regexec(&regex_int, ptr + off, &regmatch);
    if (ret == 0) {
      off = set_token_regmatch(ptr, &regmatch, TK_INT, off);
      continue;
    }
    ret = my_regexec(&regex_char, ptr + off, &regmatch);
    if (ret == 0) {
      off = set_token_regmatch(ptr, &regmatch, TK_CHAR, off);
      continue;
    }
    ret = my_regexec(&regex_string, ptr + off, &regmatch);
    if (ret == 0) {
      off = set_token_regmatch(ptr, &regmatch, TK_STRING, off);
      continue;
    }

    {
      if (!strncmp_r(ptr + off, "=="))
        off = set_token_int(ptr, 0, 2, TK_OP_EQ, off);
      else if (!strncmp_r(ptr + off, "&&"))
        off = set_token_int(ptr, 0, 2, TK_OP_AND, off);
      else if (!strncmp_r(ptr + off, "||"))
        off = set_token_int(ptr, 0, 2, TK_OP_OR, off);
      else {
        switch (ptr[off]) {
          case ';':
            off = set_token_int(ptr, 0, 1, ';', off);
            break;
          case ':':
            off = set_token_int(ptr, 0, 1, ':', off);
            break;
          case '{':
            off = set_token_int(ptr, 0, 1, '{', off);
            break;
          case '}':
            off = set_token_int(ptr, 0, 1, '}', off);
            break;
          case ',':
            off = set_token_int(ptr, 0, 1, ',', off);
            break;
          case '=':
            off = set_token_int(ptr, 0, 1, '=', off);
            break;
          case '(':
            off = set_token_int(ptr, 0, 1, '(', off);
            break;
          case ')':
            off = set_token_int(ptr, 0, 1, ')', off);
            break;
          case '&':
            off = set_token_int(ptr, 0, 1, '&', off);
            break;
          case '!':
            off = set_token_int(ptr, 0, 1, '!', off);
            break;
          case '-':
            off = set_token_int(ptr, 0, 1, '-', off);
            break;
          case '+':
            off = set_token_int(ptr, 0, 1, '+', off);
            break;
          case '*':
            off = set_token_int(ptr, 0, 1, '*', off);
            break;
          case '/':
            off = set_token_int(ptr, 0, 1, '/', off);
            break;
          case '<':
            off = set_token_int(ptr, 0, 1, '<', off);
            break;
          default:
            printf("unexpected token (%d): %s\n", off, ptr + off);
            exit(1);
        }
      }
    }
  }
}

static void dump_tokens() {
  int i;
  for (i = 0; i < MAX_TOKENS; i++) {
    struct token *token_p = &tokens[i];
    if (token_p->kind == TK_UNUSED) break;
    printf("%5d: %d-%d: %s (%s)\n", i, token_p->offset_begin,
           token_p->offset_end, token_p->lexeme,
           token_kind_string[token_p->kind]);
  }
}
/* ------------------------------------------------------- */
static void unparse_error(struct AST *ast) {
  printf("something wrong: %s\n", ast->ast_type);
  exit(1);
}

static int is_TK_type(struct AST *ast, enum token_kind kind) {
  return !strcmp(ast->ast_type, token_kind_string[kind]);
}

static void check_TK_type(struct AST *ast, enum token_kind kind) {
  if (!is_TK_type(ast, kind)) unparse_error(ast);
}

static int is_CK_type(struct AST *ast, enum grammar_constructs_kind kind) {
  return !strcmp(ast->ast_type, grammar_constructs_kind_string[kind]);
}

static void check_CK_type(struct AST *ast, enum grammar_constructs_kind kind) {
  if (!is_CK_type(ast, kind)) unparse_error(ast);
}

static void unparse_translation_unit(struct AST *ast, int depth) {
  int i = 0;
  while (i < ast->num_child) {
    printf_ns(depth, "");
    unparse_AST(ast->child[i], depth + 1);
    unparse_AST(ast->child[i + 1], depth + 1);

    if (is_TK_type(ast->child[i + 2], ';')) {
      printf(";\n");
    } else if (is_CK_type(ast->child[i + 2], CK_COMPOUND_STATEMENT)) {
      unparse_AST(ast->child[i + 2], depth);
      printf("\n\n");
    } else {
      unparse_error(ast);
    }
    i += 3;
  }
}

static void unparse_type_specifier(struct AST *ast, int depth) {
  if (is_TK_type(ast->child[0], TK_KW_VOID) ||
      is_TK_type(ast->child[0], TK_KW_CHAR) ||
      is_TK_type(ast->child[0], TK_KW_INT) ||
      is_TK_type(ast->child[0], TK_KW_LONG)) {
    printf("%s ", ast->child[0]->lexeme);
    return;
  }

  unparse_error(ast);
}

static void unparse_declarator(struct AST *ast, int depth) {
  int i = 0;
  if (is_TK_type(ast->child[0], TK_ID)) {
    printf("%s", ast->child[0]->lexeme);
  } else if (ast->num_child >= 2 && is_TK_type(ast->child[0], '*')) {
    printf("*");
    unparse_AST(ast->child[1], depth);
  } else if (ast->num_child >= 2 && is_TK_type(ast->child[0], '(')) {
    printf("(");
    unparse_AST(ast->child[1], depth);
    check_TK_type(ast->child[1], ')');
    printf(")");
  } else if (is_CK_type(ast->child[0], CK_DECLARATOR)) {
    unparse_AST(ast->child[0], depth);
    check_TK_type(ast->child[1], '(');
    printf("(");
    int i = 2;
    if (ast->num_child >= 3 &&
        is_CK_type(ast->child[2], CK_PARAMETER_DECLARATION)) {
      unparse_AST(ast->child[2], depth);
      i = 3;
      while (i + 1 < ast->num_child && is_TK_type(ast->child[i], ',')) {
        printf(", ");
        unparse_AST(ast->child[i + 1], depth);
        i += 2;
      }
    }
    check_TK_type(ast->child[i], ')');
    printf(")");
  }
}

static void unparse_parameter_declaration(struct AST *ast, int depth) {
  unparse_AST(ast->child[0], depth);
  unparse_AST(ast->child[1], depth);
}

static void unparse_compound_statement(struct AST *ast, int depth) {
  check_TK_type(ast->child[0], '{');
  printf(" {\n");
  depth++;

  int i = 1;
  while (i < ast->num_child - 1) {
    if (!is_CK_type(ast->child[i], CK_TYPE_SPECIFIER)) break;
    printf_ns(depth, "");
    unparse_AST(ast->child[i], depth);
    unparse_AST(ast->child[i + 1], depth);
    check_TK_type(ast->child[i + 2], ';');
    printf(";\n");
    i += 3;
  }

  while (i < ast->num_child - 1) {
    if (!is_CK_type(ast->child[i], CK_STATEMENT)) break;
    printf_ns(depth, "");
    unparse_AST(ast->child[i], depth);
    printf("\n");
    i += 1;
  }

  depth--;
  printf_ns(depth, "");
  check_TK_type(ast->child[i], '}');
  printf("}");
}

static void unparse_expression(struct AST *ast, int depth) {
  if (is_TK_type(ast->child[0], TK_ID) || is_TK_type(ast->child[0], TK_INT) ||
      is_TK_type(ast->child[0], TK_CHAR) ||
      is_TK_type(ast->child[0], TK_STRING)) {
    printf("%s", ast->child[0]->lexeme);
  } else if (ast->num_child >= 2 &&
             is_CK_type(ast->child[0], CK_UNARY_OPERATOR)) {
    unparse_AST(ast->child[0], depth);
    check_CK_type(ast->child[1], CK_EXPRESSION);
    unparse_AST(ast->child[0], depth);
  } else if (ast->num_child >= 3 && is_CK_type(ast->child[0], CK_EXPRESSION)) {
    unparse_AST(ast->child[0], depth);
    if (is_CK_type(ast->child[1], CK_BINARY_OPERATOR)) {
      unparse_AST(ast->child[1], depth);
      check_CK_type(ast->child[2], CK_EXPRESSION);
      unparse_AST(ast->child[2], depth);
    } else {
      check_TK_type(ast->child[1], '(');
      printf("(");
      int i = 2;
      if (ast->num_child >= 4 &&
          is_CK_type(ast->child[2], CK_ARGUMENT_EXPRESSION_LIST)) {
        unparse_AST(ast->child[2], depth);
        i++;
      }

      check_TK_type(ast->child[i], ')');
      printf(")");
    }
  } else if (ast->num_child >= 3 && is_TK_type(ast->child[0], '(')) {
    printf("(");
    check_CK_type(ast->child[1], CK_EXPRESSION);
    unparse_AST(ast->child[1], depth);
    check_TK_type(ast->child[2], ')');
    printf(")");
  } else {
    unparse_error(ast);
  }
}

static void unparse_unary_operator(struct AST *ast, int depth) {
  if (is_TK_type(ast->child[0], '&') || is_TK_type(ast->child[0], '*') ||
          is_TK_type(ast->child[0], '+') || is_TK_type(ast->child[0], '-'),
      is_TK_type(ast->child[0], '!')) {
    printf("%s", ast->child[0]->lexeme);
    return;
  }

  unparse_error(ast);
}

static void unparse_binary_operator(struct AST *ast, int depth) {
  if (is_TK_type(ast->child[0], '=') || is_TK_type(ast->child[0], TK_OP_OR) ||
          is_TK_type(ast->child[0], TK_OP_AND) ||
          is_TK_type(ast->child[0], TK_OP_EQ),
      is_TK_type(ast->child[0], '<') || is_TK_type(ast->child[0], '+') ||
          is_TK_type(ast->child[0], '*') || is_TK_type(ast->child[0], '/')) {
    printf(" %s ", ast->child[0]->lexeme);
    return;
  }

  unparse_error(ast);
}

static void unparse_argument_expression_list(struct AST *ast, int depth) {
  check_CK_type(ast->child[0], CK_EXPRESSION);
  unparse_AST(ast->child[0], depth);
  int i = 1;
  while (i < ast->num_child) {
    if (!is_TK_type(ast->child[i], ',')) break;
    check_CK_type(ast->child[i + 1], CK_EXPRESSION);
    unparse_AST(ast->child[i + 1], depth);
    i = i + 2;
  }
}
static void unparse_condition_statement(struct AST *ast, int depth) {
  check_TK_type(ast->child[1], '(');
  printf("(");
  check_CK_type(ast->child[2], CK_EXPRESSION);
  unparse_AST(ast->child[2], depth);
  check_TK_type(ast->child[3], ')');
  printf(")");
}

static void unparse_wrapped_block(struct AST *ast, int depth) {
  if (is_CK_type(ast->child[0], CK_COMPOUND_STATEMENT)) {
    unparse_AST(ast, depth);
  } else {
    printf(" {\n");
    printf_ns(depth + 1, "");
    unparse_AST(ast, depth + 1);
    printf("\n");
    printf_ns(depth, "");
    printf("}");
  }
}

static void unparse_statement(struct AST *ast, int depth) {
  if (is_TK_type(ast->child[0], TK_ID) && is_TK_type(ast->child[1], ':')) {
    printf("%s:", ast->child[0]->lexeme);
  } else if (is_CK_type(ast->child[0], CK_COMPOUND_STATEMENT)) {
    unparse_AST(ast->child[0], depth);
  } else if (is_TK_type(ast->child[0], TK_KW_IF)) {
    printf("if ");
    unparse_condition_statement(ast, depth);
    check_CK_type(ast->child[4], CK_STATEMENT);
    unparse_wrapped_block(ast->child[4], depth);

    if (ast->num_child >= 7 && is_TK_type(ast->child[5], TK_KW_ELSE)) {
      printf(" else");
      check_CK_type(ast->child[6], CK_STATEMENT);
      unparse_wrapped_block(ast->child[6], depth);
    }
  } else if (is_TK_type(ast->child[0], TK_KW_WHILE)) {
    printf("while ");
    unparse_condition_statement(ast, depth);
    check_CK_type(ast->child[4], CK_STATEMENT);
    unparse_wrapped_block(ast->child[4], depth);
  } else if (is_TK_type(ast->child[0], TK_KW_GOTO)) {
    check_TK_type(ast->child[1], TK_ID);
    printf("goto %s", ast->child[1]->lexeme);
    check_TK_type(ast->child[2], ';');
    printf(";");
  } else if (is_TK_type(ast->child[0], TK_KW_RETURN)) {
    printf("return");
    int i = 1;
    if (ast->num_child >= 2 && is_CK_type(ast->child[1], CK_EXPRESSION)) {
      printf(" ");
      unparse_AST(ast->child[1], depth);
      i++;
    }
    check_TK_type(ast->child[i], ';');
    printf(";");
  } else if (is_CK_type(ast->child[0], CK_EXPRESSION)) {
    unparse_AST(ast->child[0], depth);
    check_TK_type(ast->child[1], ';');
    printf(";");
  } else if (is_TK_type(ast->child[0], ';')) {
    printf(";");
  } else {
    unparse_error(ast);
  }
}

static void unparse_AST(struct AST *ast, int depth) {
  if (is_CK_type(ast, CK_TRANSLATION_UNIT)) {
    unparse_translation_unit(ast, depth);
  } else if (is_CK_type(ast, CK_TYPE_SPECIFIER)) {
    unparse_type_specifier(ast, depth);
  } else if (is_CK_type(ast, CK_DECLARATOR)) {
    unparse_declarator(ast, depth);
  } else if (is_CK_type(ast, CK_COMPOUND_STATEMENT)) {
    unparse_compound_statement(ast, depth);
  } else if (is_CK_type(ast, CK_EXPRESSION)) {
    unparse_expression(ast, depth);
  } else if (is_CK_type(ast, CK_UNARY_OPERATOR)) {
    unparse_unary_operator(ast, depth);
  } else if (is_CK_type(ast, CK_BINARY_OPERATOR)) {
    unparse_binary_operator(ast, depth);
  } else if (is_CK_type(ast, CK_ARGUMENT_EXPRESSION_LIST)) {
    unparse_argument_expression_list(ast, depth);
  } else if (is_CK_type(ast, CK_STATEMENT)) {
    unparse_statement(ast, depth);
  } else {
    unparse_error(ast);
  }
}
/* ------------------------------------------------------- */

int main(int argc, char *argv[]) {
  char *ptr;
  struct AST *ast;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  ptr = map_file(argv[1]);
  create_tokens(ptr);
  reset_tokens();
  // dump_tokens();  // 提出時はコメントアウトしておくこと

  ast = parse_translation_unit();
  // show_AST(ast, 0);  // 提出時はコメントアウトしておくこと
  // printf("\n");
  unparse_AST(ast, 0);
}
