#include <stdio.h>

int b[15][15];

int
construct_pascal_tri (int n, int k)
{
        if (n == 0|| n == k || k == 0)
                return 1;

        b[n][k] = construct_pascal_tri (n - 1, k - 1) +
                  construct_pascal_tri (n - 1, k);
        printf ("b[%d][%d]=%d\n", n, k, b[n][k]);
        return b[n][k];
}

int
main()
{
        int i, j, n = 10;

        construct_pascal_tri (10, 8);

        for (i = 0; i < n; i++) {
                for (j = 0; j <= i; j++) {
                        printf ("%d ", b[i][j]);
                }
                printf ("\n");
        }
        return 0;
}
