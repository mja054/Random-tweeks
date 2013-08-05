#include <iostream>
#include <stdio.h>
using namespace std;

int count = 0;

void
dfs(int a[][10], int *v, int n, int cur)
{
        v[cur] = ++count;

        for (int i = 0; i < n; i++)
                if (a[cur][i] && !v[i])
                        dfs(a, v, n, i);
}

void
DFS(int a[][10], int *v, int n)
{
        for (int i = 0; i < n; i++)
                if (!v[i])
                        dfs(a, v, n, i);
}

int
main ()
{
        char g[10] = {'a', 'b', 'c', 'd', 'e',
                      'f', 'g', 'h', 'i', 'j'};
        int a[10][10] = {{0, 0, 0, 0, 1},
                         {0, 0, 1, 0, 0},
                         {0, 1, 0, 1, 1},
                         {0, 0, 1, 0, 1},
                         {1, 0, 1, 1, 0}};
        int v[10] = {0, };
        int n, i;

        n = 5;

        DFS(a, v, n);

        cout << "dfs traversal of\n";
        for (i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++)
                        cout << a[i][j] << " ";
                cout << endl;
        }
        cout << endl;

        for (i = 0; i < n; i++)
                printf ("%c -> %d\n", g[i], v[i]);

        return 0;
}
