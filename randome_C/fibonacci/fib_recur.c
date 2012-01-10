#include<stdio.h>

int
fib(int n)
{
        int ans;
        if (n == 0 || n == 1)
                return 1;
        ans = fib (n-1) + fib (n-2);
        return ans;
}

int
main()
{
        int n=45;
//      scanf ("%d", &n);
        printf ("fibnacci of %d=%d\n", n, fib(n));
        return 0;
}
