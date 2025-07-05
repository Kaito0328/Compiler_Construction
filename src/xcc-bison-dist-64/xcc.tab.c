/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "xcc.y"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "xcc.h"
#include "misc.h"
#include "AST.h"
#include "type.h"
#include "symbol.h"
#include "codegen.h"
#ifdef XCC_VIS
#include "vis/vis.h"
#endif
#define YYERROR_VERBOSE

struct AST *ast_root;
char       *filename;
FILE       *xcc_out;
int AST_is_local = 0;

static void init (int argc, char *argv []);

#line 96 "xcc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "xcc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* "char"  */
  YYSYMBOL_ELSE = 4,                       /* "else"  */
  YYSYMBOL_GOTO = 5,                       /* "goto"  */
  YYSYMBOL_IF = 6,                         /* "if"  */
  YYSYMBOL_INT = 7,                        /* "int"  */
  YYSYMBOL_LONG = 8,                       /* "long"  */
  YYSYMBOL_RETURN = 9,                     /* "return"  */
  YYSYMBOL_VOID = 10,                      /* "void"  */
  YYSYMBOL_WHILE = 11,                     /* "while"  */
  YYSYMBOL_EQ = 12,                        /* "=="  */
  YYSYMBOL_AND = 13,                       /* "&&"  */
  YYSYMBOL_OR = 14,                        /* "||"  */
  YYSYMBOL_IDENTIFIER = 15,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 16,                    /* STRING  */
  YYSYMBOL_INTEGER_CONSTANT = 17,          /* INTEGER_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 18,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* '<'  */
  YYSYMBOL_21_ = 21,                       /* '+'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '*'  */
  YYSYMBOL_24_ = 24,                       /* '/'  */
  YYSYMBOL_UNARY_OP = 25,                  /* UNARY_OP  */
  YYSYMBOL_26_ = 26,                       /* '('  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_30_ = 30,                       /* ':'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* '&'  */
  YYSYMBOL_34_ = 34,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_translation_unit = 36,          /* translation_unit  */
  YYSYMBOL_external_declaration = 37,      /* external_declaration  */
  YYSYMBOL_function_definition = 38,       /* function_definition  */
  YYSYMBOL_39_1 = 39,                      /* @1  */
  YYSYMBOL_declaration_list = 40,          /* declaration_list  */
  YYSYMBOL_declaration = 41,               /* declaration  */
  YYSYMBOL_type_specifier = 42,            /* type_specifier  */
  YYSYMBOL_declarator = 43,                /* declarator  */
  YYSYMBOL_parameter_list = 44,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 45,     /* parameter_declaration  */
  YYSYMBOL_statement_list = 46,            /* statement_list  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_compound_statement = 48,        /* compound_statement  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_expression_opt = 51,            /* expression_opt  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_unary_operator = 53,            /* unary_operator  */
  YYSYMBOL_argument_expression_list = 54,  /* argument_expression_list  */
  YYSYMBOL_identifier = 55                 /* identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,     2,    33,     2,
      26,    28,    23,    21,    29,    22,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,    27,
      20,    19,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    73,    79,    81,    90,    89,   106,   107,
     112,   119,   121,   123,   125,   130,   132,   134,   136,   138,
     143,   145,   150,   157,   159,   164,   166,   168,   170,   172,
     174,   176,   179,   185,   187,   184,   195,   196,   201,   206,
     209,   222,   225,   228,   231,   234,   237,   240,   243,   246,
     249,   252,   255,   258,   261,   267,   268,   269,   270,   271,
     275,   279,   286
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"char\"", "\"else\"",
  "\"goto\"", "\"if\"", "\"int\"", "\"long\"", "\"return\"", "\"void\"",
  "\"while\"", "\"==\"", "\"&&\"", "\"||\"", "IDENTIFIER", "STRING",
  "INTEGER_CONSTANT", "CHARACTER_CONSTANT", "'='", "'<'", "'+'", "'-'",
  "'*'", "'/'", "UNARY_OP", "'('", "';'", "')'", "','", "':'", "'{'",
  "'}'", "'&'", "'!'", "$accept", "translation_unit",
  "external_declaration", "function_definition", "@1", "declaration_list",
  "declaration", "type_specifier", "declarator", "parameter_list",
  "parameter_declaration", "statement_list", "statement",
  "compound_statement", "$@2", "$@3", "expression_opt", "expression",
  "unary_operator", "argument_expression_list", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      98,   -51,   -51,   -51,   -51,   224,   -51,   -51,   -51,   -12,
     -51,   -51,   -51,   -12,   -12,    -8,   -51,   -16,    46,    14,
     -51,   -23,   -51,   -51,   -12,    16,   -51,   -51,   -51,   -16,
     -51,    98,   -51,   -51,    98,   -51,   -12,    76,    -8,    10,
      15,   110,    32,   -51,   -51,   -51,   -51,   -51,   -51,   110,
     -51,   -51,    45,   -51,   -51,    38,   177,   110,    29,    48,
     110,    53,   -51,   110,   126,   -51,   -51,   -51,   110,   110,
     110,   110,   110,   110,   110,   110,   110,    96,    47,    76,
     -51,   143,   -51,   160,   -51,   215,   199,   192,   177,   221,
     -17,   -17,    47,    47,   -51,   177,    24,   -51,    76,    76,
     -51,   110,    79,   -51,   177,    76,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    13,    14,    11,     0,     2,     4,     5,     0,
       1,     3,    62,     0,     0,     6,    15,    16,     0,     0,
      10,     0,    17,    19,     0,     0,    20,    33,     7,    22,
      18,     0,     8,    21,    34,     9,     0,    36,     0,     0,
       0,    36,     0,    41,    39,    40,    57,    58,    56,     0,
      55,    59,    36,    23,    26,     0,    37,     0,    38,     0,
       0,     0,    38,     0,     0,    35,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    36,
      30,     0,    32,     0,    54,    45,    44,    43,    42,    46,
      47,    48,    49,    50,    53,    60,     0,    31,    36,    36,
      52,     0,    27,    29,    61,    36,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,    81,   -51,   -51,   -51,    50,   -18,    33,   -51,
      57,   -51,   -50,    74,   -51,   -51,    59,   -37,   -51,   -51,
      -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    21,    34,     8,     9,    15,    25,
      26,    52,    53,    54,    32,    37,    55,    56,    57,    96,
      62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      16,    24,    66,    12,    16,    16,    75,    76,    27,    77,
      19,    13,    64,    24,    14,    16,    36,     1,    19,    20,
      78,     2,     3,    81,     4,    12,    83,    16,    58,    97,
      59,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      95,    60,    23,    58,    30,    31,    17,    18,   102,   103,
      39,    40,   100,   101,    41,   106,    42,    29,    63,    79,
      12,    43,    44,    45,   104,    67,    46,    47,    48,    38,
      58,    49,    19,    77,    22,    80,    27,    65,    50,    51,
      82,    39,    40,   105,    35,    41,    11,    42,    33,    58,
      58,    12,    43,    44,    45,    28,    58,    46,    47,    48,
      61,     1,    49,     0,     0,     2,     3,    27,     4,    50,
      51,    12,    43,    44,    45,     0,     0,    46,    47,    48,
       0,     0,    49,     0,    94,    12,    43,    44,    45,    50,
      51,    46,    47,    48,     0,     0,    49,     0,    68,    69,
      70,     0,     0,    50,    51,    71,    72,    73,    74,    75,
      76,     0,    77,     0,    84,    68,    69,    70,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,     0,    77,
       0,    98,    68,    69,    70,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,     0,    77,     0,    99,    68,
      69,    70,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,     0,    77,    68,    69,     0,     0,     0,     0,
       0,    68,    72,    73,    74,    75,    76,     0,    77,    72,
      73,    74,    75,    76,    10,    77,     0,     1,     0,     0,
       0,     2,     3,     0,     4,    72,    73,    74,    75,    76,
       0,    77,    73,    74,    75,    76,     0,    77
};

static const yytype_int8 yycheck[] =
{
       9,    19,    52,    15,    13,    14,    23,    24,    31,    26,
      26,    23,    49,    31,    26,    24,    34,     3,    26,    27,
      57,     7,     8,    60,    10,    15,    63,    36,    37,    79,
      39,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    26,    28,    52,    28,    29,    13,    14,    98,    99,
       5,     6,    28,    29,     9,   105,    11,    24,    26,    30,
      15,    16,    17,    18,   101,    27,    21,    22,    23,    36,
      79,    26,    26,    26,    28,    27,    31,    32,    33,    34,
      27,     5,     6,     4,    34,     9,     5,    11,    31,    98,
      99,    15,    16,    17,    18,    21,   105,    21,    22,    23,
      41,     3,    26,    -1,    -1,     7,     8,    31,    10,    33,
      34,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      -1,    -1,    26,    -1,    28,    15,    16,    17,    18,    33,
      34,    21,    22,    23,    -1,    -1,    26,    -1,    12,    13,
      14,    -1,    -1,    33,    34,    19,    20,    21,    22,    23,
      24,    -1,    26,    -1,    28,    12,    13,    14,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      -1,    28,    12,    13,    14,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    -1,    28,    12,
      13,    14,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    12,    13,    -1,    -1,    -1,    -1,
      -1,    12,    20,    21,    22,    23,    24,    -1,    26,    20,
      21,    22,    23,    24,     0,    26,    -1,     3,    -1,    -1,
      -1,     7,     8,    -1,    10,    20,    21,    22,    23,    24,
      -1,    26,    21,    22,    23,    24,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,     8,    10,    36,    37,    38,    41,    42,
       0,    37,    15,    23,    26,    43,    55,    43,    43,    26,
      27,    39,    28,    28,    42,    44,    45,    31,    48,    43,
      28,    29,    49,    45,    40,    41,    42,    50,    43,     5,
       6,     9,    11,    16,    17,    18,    21,    22,    23,    26,
      33,    34,    46,    47,    48,    51,    52,    53,    55,    55,
      26,    51,    55,    26,    52,    32,    47,    27,    12,    13,
      14,    19,    20,    21,    22,    23,    24,    26,    52,    30,
      27,    52,    27,    52,    28,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    28,    52,    54,    47,    28,    28,
      28,    29,    47,    47,    52,     4,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    39,    38,    40,    40,
      41,    42,    42,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    49,    50,    48,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     0,     4,     0,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     4,     3,
       1,     3,     2,     1,     2,     2,     1,     5,     7,     5,
       3,     3,     3,     0,     0,     6,     0,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* translation_unit: external_declaration  */
#line 71 "xcc.y"
        { yyval = create_AST ("AST_translation_unit_single", 1, yyvsp[0]);
	  ast_root = yyval; }
#line 1236 "xcc.tab.c"
    break;

  case 3: /* translation_unit: translation_unit external_declaration  */
#line 74 "xcc.y"
        { yyval = create_AST ("AST_translation_unit_pair", 2, yyvsp[-1], yyvsp[0]);
	  ast_root = yyval; }
#line 1243 "xcc.tab.c"
    break;

  case 4: /* external_declaration: function_definition  */
#line 80 "xcc.y"
        { yyval = create_AST ("AST_external_declaration_func", 1, yyvsp[0]); }
#line 1249 "xcc.tab.c"
    break;

  case 5: /* external_declaration: declaration  */
#line 82 "xcc.y"
        { yyval = create_AST ("AST_external_declaration_dec", 1, yyvsp[0]); 
	  sym_table.arg    = NULL;
  	  sym_table.label  = NULL;
  	  sym_table.string = NULL; }
#line 1258 "xcc.tab.c"
    break;

  case 6: /* @1: %empty  */
#line 90 "xcc.y"
        { yyval = create_AST ("AST_dummy", 2, yyvsp[-1], yyvsp[0]);
	  yyval->type = type_analyze_declarator (yyvsp[0], yyvsp[-1]->type); 
          /* conditonal to cause more natural syntax error */
          if (yyval->type->kind == TYPE_KIND_FUNCTION) {
              sym_entry_param (yyval->type);
              sym_entry (yyval);
              sym_begin_function ();
          } }
#line 1271 "xcc.tab.c"
    break;

  case 7: /* function_definition: type_specifier declarator @1 compound_statement  */
#line 99 "xcc.y"
        { yyval = create_AST ("AST_function_definition", 3, yyvsp[-3], yyvsp[-2], yyvsp[0]);
          sym_backpatch (yyval, yyvsp[-1]->type);
	  sym_end_function (yyval); }
#line 1279 "xcc.tab.c"
    break;

  case 8: /* declaration_list: %empty  */
#line 106 "xcc.y"
        { yyval = create_AST ("AST_declaration_list_null", 0); }
#line 1285 "xcc.tab.c"
    break;

  case 9: /* declaration_list: declaration_list declaration  */
#line 108 "xcc.y"
        { yyval = create_AST ("AST_declaration_list_pair", 2, yyvsp[-1], yyvsp[0]); }
#line 1291 "xcc.tab.c"
    break;

  case 10: /* declaration: type_specifier declarator ';'  */
#line 113 "xcc.y"
        { yyval = create_AST ("AST_declaration", 2, yyvsp[-2], yyvsp[-1]); 
	  yyval->type = type_analyze_declarator (yyvsp[-1], yyvsp[-2]->type);
	  sym_entry (yyval); }
#line 1299 "xcc.tab.c"
    break;

  case 11: /* type_specifier: "void"  */
#line 119 "xcc.y"
             { yyval = create_AST ("AST_type_specifier_void", 0);
               yyval->type = create_prim_type (PRIM_TYPE_VOID); }
#line 1306 "xcc.tab.c"
    break;

  case 12: /* type_specifier: "char"  */
#line 121 "xcc.y"
             { yyval = create_AST ("AST_type_specifier_char", 0);
               yyval->type = create_prim_type (PRIM_TYPE_CHAR); }
#line 1313 "xcc.tab.c"
    break;

  case 13: /* type_specifier: "int"  */
#line 123 "xcc.y"
             { yyval = create_AST ("AST_type_specifier_int", 0);
               yyval->type = create_prim_type (PRIM_TYPE_INT); }
#line 1320 "xcc.tab.c"
    break;

  case 14: /* type_specifier: "long"  */
#line 125 "xcc.y"
             { yyval = create_AST ("AST_type_specifier_long", 0);
               yyval->type = create_prim_type (PRIM_TYPE_LONG); }
#line 1327 "xcc.tab.c"
    break;

  case 15: /* declarator: identifier  */
#line 131 "xcc.y"
        { yyval = create_AST ("AST_declarator_id", 1, yyvsp[0]); }
#line 1333 "xcc.tab.c"
    break;

  case 16: /* declarator: '*' declarator  */
#line 133 "xcc.y"
        { yyval = create_AST ("AST_declarator_pointer", 1, yyvsp[0]); }
#line 1339 "xcc.tab.c"
    break;

  case 17: /* declarator: '(' declarator ')'  */
#line 135 "xcc.y"
        { yyval = create_AST ("AST_declarator_paren", 1, yyvsp[-1]); }
#line 1345 "xcc.tab.c"
    break;

  case 18: /* declarator: declarator '(' parameter_list ')'  */
#line 137 "xcc.y"
        { yyval = create_AST ("AST_declarator_func1", 2, yyvsp[-3], yyvsp[-1]); }
#line 1351 "xcc.tab.c"
    break;

  case 19: /* declarator: declarator '(' ')'  */
#line 139 "xcc.y"
        { yyval = create_AST ("AST_declarator_func2", 1, yyvsp[-2]); }
#line 1357 "xcc.tab.c"
    break;

  case 20: /* parameter_list: parameter_declaration  */
#line 144 "xcc.y"
        { yyval = create_AST ("AST_parameter_list_single", 1, yyvsp[0]); }
#line 1363 "xcc.tab.c"
    break;

  case 21: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 146 "xcc.y"
        { yyval = create_AST ("AST_parameter_list_pair", 2, yyvsp[-2], yyvsp[0]); }
#line 1369 "xcc.tab.c"
    break;

  case 22: /* parameter_declaration: type_specifier declarator  */
#line 151 "xcc.y"
        { yyval = create_AST ("AST_parameter_declaration", 2, yyvsp[-1], yyvsp[0]);
	  yyval->type = type_analyze_declarator (yyvsp[0], yyvsp[-1]->type);
	  /* sym_entry ($$); */ }
#line 1377 "xcc.tab.c"
    break;

  case 23: /* statement_list: statement  */
#line 158 "xcc.y"
        { yyval = create_AST ("AST_statement_list_single", 1, yyvsp[0]); }
#line 1383 "xcc.tab.c"
    break;

  case 24: /* statement_list: statement_list statement  */
#line 160 "xcc.y"
        { yyval = create_AST ("AST_statement_list_pair", 2, yyvsp[-1], yyvsp[0]); }
#line 1389 "xcc.tab.c"
    break;

  case 25: /* statement: expression_opt ';'  */
#line 165 "xcc.y"
        { yyval = create_AST ("AST_statement_exp", 1, yyvsp[-1]); }
#line 1395 "xcc.tab.c"
    break;

  case 26: /* statement: compound_statement  */
#line 167 "xcc.y"
        { yyval = create_AST ("AST_statement_comp", 1, yyvsp[0]); }
#line 1401 "xcc.tab.c"
    break;

  case 27: /* statement: "if" '(' expression ')' statement  */
#line 169 "xcc.y"
        { yyval = create_AST ("AST_statement_if", 2, yyvsp[-2], yyvsp[0]); }
#line 1407 "xcc.tab.c"
    break;

  case 28: /* statement: "if" '(' expression ')' statement "else" statement  */
#line 171 "xcc.y"
        { yyval = create_AST ("AST_statement_ifelse", 3, yyvsp[-4], yyvsp[-2], yyvsp[0]); }
#line 1413 "xcc.tab.c"
    break;

  case 29: /* statement: "while" '(' expression ')' statement  */
#line 173 "xcc.y"
        { yyval = create_AST ("AST_statement_while", 2, yyvsp[-2], yyvsp[0]); }
#line 1419 "xcc.tab.c"
    break;

  case 30: /* statement: "goto" identifier ';'  */
#line 175 "xcc.y"
        { yyval = create_AST ("AST_statement_goto", 1, yyvsp[-1]); }
#line 1425 "xcc.tab.c"
    break;

  case 31: /* statement: identifier ':' statement  */
#line 177 "xcc.y"
        { yyval = create_AST ("AST_statement_label", 2, yyvsp[-2], yyvsp[0]);
	  sym_entry (yyval); }
#line 1432 "xcc.tab.c"
    break;

  case 32: /* statement: "return" expression_opt ';'  */
#line 180 "xcc.y"
        { yyval = create_AST ("AST_statement_return", 1, yyvsp[-1]); }
#line 1438 "xcc.tab.c"
    break;

  case 33: /* $@2: %empty  */
#line 185 "xcc.y"
        { sym_begin_block (); }
#line 1444 "xcc.tab.c"
    break;

  case 34: /* $@3: %empty  */
#line 187 "xcc.y"
        { sym_middle_block (); }
#line 1450 "xcc.tab.c"
    break;

  case 35: /* compound_statement: '{' $@2 declaration_list $@3 statement_list '}'  */
#line 189 "xcc.y"
        { yyval = create_AST ("AST_compound_statement", 2, yyvsp[-3], yyvsp[-1]);
	  sym_end_block (yyval); }
#line 1457 "xcc.tab.c"
    break;

  case 36: /* expression_opt: %empty  */
#line 195 "xcc.y"
        { yyval = create_AST ("AST_expression_opt_null", 0); }
#line 1463 "xcc.tab.c"
    break;

  case 37: /* expression_opt: expression  */
#line 197 "xcc.y"
        { yyval = create_AST ("AST_expression_opt_single", 1, yyvsp[0]); }
#line 1469 "xcc.tab.c"
    break;

  case 38: /* expression: identifier  */
#line 202 "xcc.y"
        { struct Symbol *sym;
          yyval = create_AST ("AST_expression_id", 1, yyvsp[0]);
          sym = sym_check_var_decl (yyval);
	  yyval->type = sym->type; }
#line 1478 "xcc.tab.c"
    break;

  case 39: /* expression: INTEGER_CONSTANT  */
#line 207 "xcc.y"
        { yyval = create_AST ("AST_expression_long", 1, atol (yytext));
            yyval->type = types.t_long; }
#line 1485 "xcc.tab.c"
    break;

  case 40: /* expression: CHARACTER_CONSTANT  */
#line 210 "xcc.y"
        { 
          char c;
          if (yytext [1] == '\\') { /* escape sequence */
              switch (yytext [2]) {
              case 'n': c = '\n';   break;
              default:  assert (0); break;
              }
          } else { /* normal character */
              c = yytext [1];
          }
          yyval = create_AST ("AST_expression_char", 1, c);
	  yyval->type = types.t_long; }
#line 1502 "xcc.tab.c"
    break;

  case 41: /* expression: STRING  */
#line 223 "xcc.y"
        { yyval = create_AST ("AST_expression_string", 1, str_buf);
	  yyval->type = types.t_char_p; string_entry (yyval->u.id); }
#line 1509 "xcc.tab.c"
    break;

  case 42: /* expression: expression '=' expression  */
#line 226 "xcc.y"
        { yyval = create_AST ("AST_expression_assign", 2, yyvsp[-2], yyvsp[0]);
	  yyval->type = yyvsp[-2]->type; }
#line 1516 "xcc.tab.c"
    break;

  case 43: /* expression: expression "||" expression  */
#line 229 "xcc.y"
        { yyval = create_AST ("AST_expression_lor",    2, yyvsp[-2], yyvsp[0]);
	  yyval->type = types.t_long; }
#line 1523 "xcc.tab.c"
    break;

  case 44: /* expression: expression "&&" expression  */
#line 232 "xcc.y"
        { yyval = create_AST ("AST_expression_land",   2, yyvsp[-2], yyvsp[0]);
	  yyval->type = types.t_long; }
#line 1530 "xcc.tab.c"
    break;

  case 45: /* expression: expression "==" expression  */
#line 235 "xcc.y"
        { yyval = create_AST ("AST_expression_eq",     2, yyvsp[-2], yyvsp[0]);
	  yyval->type = types.t_long; }
#line 1537 "xcc.tab.c"
    break;

  case 46: /* expression: expression '<' expression  */
#line 238 "xcc.y"
        { yyval = create_AST ("AST_expression_less",   2, yyvsp[-2], yyvsp[0]);
	  yyval->type = types.t_long; }
#line 1544 "xcc.tab.c"
    break;

  case 47: /* expression: expression '+' expression  */
#line 241 "xcc.y"
        { yyval = create_AST ("AST_expression_add",    2, yyvsp[-2], yyvsp[0]);
	  yyval->type = type_add (yyvsp[-2]->type, yyvsp[0]->type); }
#line 1551 "xcc.tab.c"
    break;

  case 48: /* expression: expression '-' expression  */
#line 244 "xcc.y"
        { yyval = create_AST ("AST_expression_sub",    2, yyvsp[-2], yyvsp[0]);
	  yyval->type = type_sub (yyvsp[-2]->type, yyvsp[0]->type); }
#line 1558 "xcc.tab.c"
    break;

  case 49: /* expression: expression '*' expression  */
#line 247 "xcc.y"
        { yyval = create_AST ("AST_expression_mul",    2, yyvsp[-2], yyvsp[0]);
	  yyval->type = types.t_long; }
#line 1565 "xcc.tab.c"
    break;

  case 50: /* expression: expression '/' expression  */
#line 250 "xcc.y"
        { yyval = create_AST ("AST_expression_div",    2, yyvsp[-2], yyvsp[0]);
	  yyval->type = types.t_long; }
#line 1572 "xcc.tab.c"
    break;

  case 51: /* expression: unary_operator expression  */
#line 253 "xcc.y"
        { yyval = create_AST ("AST_expression_unary",  2, yyvsp[-1], yyvsp[0]);
	  yyval->type = type_uop (yyvsp[-1], yyvsp[0]->type); }
#line 1579 "xcc.tab.c"
    break;

  case 52: /* expression: expression '(' argument_expression_list ')'  */
#line 256 "xcc.y"
        { yyval = create_AST ("AST_expression_funcall1", 2, yyvsp[-3], yyvsp[-1]);
	  yyval->type = yyvsp[-3]->type->u.t_function.ret_type; }
#line 1586 "xcc.tab.c"
    break;

  case 53: /* expression: expression '(' ')'  */
#line 259 "xcc.y"
        { yyval = create_AST ("AST_expression_funcall2", 1, yyvsp[-2]);
	  yyval->type = yyvsp[-2]->type->u.t_function.ret_type; }
#line 1593 "xcc.tab.c"
    break;

  case 54: /* expression: '(' expression ')'  */
#line 262 "xcc.y"
        { yyval = create_AST ("AST_expression_paren", 1, yyvsp[-1]);
	  yyval->type = yyvsp[-1]->type; }
#line 1600 "xcc.tab.c"
    break;

  case 55: /* unary_operator: '&'  */
#line 267 "xcc.y"
          { yyval = create_AST ("AST_unary_operator_address",  0); }
#line 1606 "xcc.tab.c"
    break;

  case 56: /* unary_operator: '*'  */
#line 268 "xcc.y"
          { yyval = create_AST ("AST_unary_operator_deref",    0); }
#line 1612 "xcc.tab.c"
    break;

  case 57: /* unary_operator: '+'  */
#line 269 "xcc.y"
          { yyval = create_AST ("AST_unary_operator_plus",     0); }
#line 1618 "xcc.tab.c"
    break;

  case 58: /* unary_operator: '-'  */
#line 270 "xcc.y"
          { yyval = create_AST ("AST_unary_operator_minus",    0); }
#line 1624 "xcc.tab.c"
    break;

  case 59: /* unary_operator: '!'  */
#line 271 "xcc.y"
          { yyval = create_AST ("AST_unary_operator_negative", 0); }
#line 1630 "xcc.tab.c"
    break;

  case 60: /* argument_expression_list: expression  */
#line 276 "xcc.y"
        { yyval = create_AST ("AST_argument_expression_list_single", 1, yyvsp[0]);
            // $$->u.arg_size = ROUNDUP_LONG ($1->type->size); // xxx
        }
#line 1638 "xcc.tab.c"
    break;

  case 61: /* argument_expression_list: argument_expression_list ',' expression  */
#line 280 "xcc.y"
        { yyval = create_AST ("AST_argument_expression_list_pair", 2, yyvsp[-2], yyvsp[0]);
            // $$->u.arg_size = $1->u.arg_size + ROUNDUP_LONG ($3->type->size); // xxx
        }
#line 1646 "xcc.tab.c"
    break;

  case 62: /* identifier: IDENTIFIER  */
#line 286 "xcc.y"
                 { yyval = create_AST ("AST_IDENTIFIER", 1, yytext); }
#line 1652 "xcc.tab.c"
    break;


#line 1656 "xcc.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 288 "xcc.y"

/* ---------------------------------------------------------------------- */
static void
init (int argc, char *argv [])
{
    /* handling command line arguments */
    if (argc < 2) {
	fprintf (stderr, "Usage: %s filename\n", argv [0]);
	exit (1);
    }
    filename = argv [1];
    yyin = fopen (filename, "r");
    if (yyin == NULL) {
	fprintf (stderr, "Cannot open file: %s\n", argv [1]);
	exit (1);
    }

    /* initialization for types */
    types.t_void   = create_prim_type (PRIM_TYPE_VOID);
    types.t_char   = create_prim_type (PRIM_TYPE_CHAR);
    types.t_int    = create_prim_type (PRIM_TYPE_INT);
    types.t_long   = create_prim_type (PRIM_TYPE_LONG);
    types.t_char_p = create_pointer_type (types.t_char);

    xcc_out = stdout;
}
/* --------------------------------------------------------------------- */
int
yyerror (const char *mesg)
{
    fprintf (stderr, "yyerror: %d: %s around `%s'\n",
	     lineno, mesg, yytext);
    exit (1);
}

int
main (int argc, char *argv [])
{
    init (argc, argv);
    yyparse (); /* semantic analysis is also done in actions */
#ifdef XCC_VIS
    xcc_vis_main (ast_root, 0);
#endif
    codegen ();
    return 0;
}

int yywrap (void) {
    return 1;
}
/* --------------------------------------------------------------------- */
