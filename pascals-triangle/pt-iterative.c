#include <stdio.h>

int
main()
{
        int b[15][15];
        int i, j, n = 10;

        for (i = 0; i < n; i++) {
                b[i][0] = 1;
                b[i][i] = 1;
        }

        for (i = 2; i < n; i++) {
                for (j = 1; j < i; j++) {
                        b[i][j] = b[i-1][j-1] + b[i-1][j];
                }
        }

        for (i = 0; i < n; i++) {
                for (j = 0; j <= i; j++) {
                        printf ("%d ", b[i][j]);
                }
                printf ("\n");
        }
        return 0;
}
