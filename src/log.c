#include <stdio.h>

#if 1 // 0にするとログ出力オフ
#define MYLOG(fmt, ...) do { fprintf (stderr, "%s:%d:%s: ", __FILE__, __LINE__, __FUNCTION__); fprintf (stderr, fmt, __VA_ARGS__); } while (0)
#else
#define MYLOG(fmt, ...) 
#endif

int 
fact (int n)
{
    MYLOG ("-> n=%d\n", n);
    if (n <= 0) {
        return 1;
    } else {
        return n * fact (n - 1);
    }
}

int
main (int argc, char **argv)
{
    MYLOG ("argc=%d\n", argc);
    printf ("%d\n", fact (5)); 
}
