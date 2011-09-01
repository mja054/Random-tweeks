#include<stdio.h>

int
main()
{
        int n=46, i, f1 = 1, f2 = 1, f3;
        for (i = 2; i < n; i++) {
                f3 = f1 + f2;
                f1 = f2;
                f2 = f3;
        }

        printf ("fibnacci of %d=%d\n", n, f3);
        return 0;
}
