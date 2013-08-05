#include <stdio.h>
#include <regex.h>


void
fun ()
{
        char str[] = "^[:alpha:]+[:digit:]";
        regex_t myregex;
        regmatch_t pmatch[10] = {{0,}};;
        int ret;

        ret = regcomp (&myregex, str, 0); //"^a[[:alnum:]]", 0);
        if (ret) {
                printf ("regcomp returned error: %d\n", ret);
                return;
        }

        ret = regexec (&myregex, "abc", 10, pmatch, 0); //, pmatch, 0);
        if (ret == REG_NOMATCH) {
                printf ("regexec returned error: %d\n", ret);
                return;
        }

        return;
}

int
main ()
{
        fun ();
}
