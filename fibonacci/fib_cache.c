#include<stdio.h>
#define MAX 45
#define UNKOWN -1

int f[MAX + 1] = {1, 1};

int
fib (int n)
{
        if (f[n] == UNKOWN)
                f[n] = fib (n-1) + fib (n-2);
        return f[n];
}

int
main()
{
        int n=45, i;
//      scanf ("%d", &n);
        for (i = 2; i < (MAX + 1); i++)
                f[i] = -1;

        printf ("fibnacci of %d=%d\n", n, fib(n));
        return 0;
}
