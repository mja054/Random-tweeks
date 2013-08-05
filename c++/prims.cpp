#include <iostream>

using namespace std;

#define MAX 1024 // for this example, let us assume that 1024 is the 
                 //maximum cost possible.

int min_span[10][10];
int vertices_covered[2][10];

int
is_seen(int node)
{
        return vertices_covered[1][node];
}

int
next_vertex(int node)
{
        return vertices_covered[0][node];
}

void
mark_covered(int node)
{
        vertices_covered[1][node] = 1;
}

void
add_vertex(int index, int node)
{
        vertices_covered[0][index] = node;
}

int
find_next (int graph[10][10], int n, int index, int &cost)
{
        int i, min = MAX, vertex;

        for (i = 0; i < n; i++) {
                if (!is_seen(i)) //vertex not covered
                        if (graph[index][i] && graph[index][i] < min) {
                                vertex = i;
                                min    = graph[index][i];
                        }
        }
        cost = min;
        return vertex;
}

void
prims_algo(int graph[10][10], int n)
{
        int i, j, x, y, min, edge_cost, tmp, vertex;

        // initially start with an arbitrary vertex, in our case vertex 0
        add_vertex(0, 0);
        mark_covered(0);

        // Run the loop n times to reach all the n nodes
        for(i = 1; i < n; i++) {
                min = MAX;

                // Now run the loop over the traversed set of vertices to find
                // the next vertex to be added.
                for (j = 0; j < i; j++) {
                        vertex = next_vertex(j);
                        tmp = find_next(graph, n, vertex, edge_cost);
                        if (edge_cost < min) {
                                min = edge_cost; // cost to reach the next node
                                y = tmp;         // the next vertex to be added
                                                 // to the seen list.
                                x = vertex;      // vertex from which
                                                 // the other end of the edge.
                        }
                }
                add_vertex(i, y);      // add the recently covered vertex
                mark_covered(y);
                min_span[x][y] = min;  // update the spanning tree
                min_span[y][x] = min;
        }
}

int
main ()
{
        int graph[10][10] = {{ 0, 5, 10, 0, 0},
                             { 5, 0,  0, 6, 0},
                             {10, 0,  0, 2, 0},
                             { 0, 6,  2, 0, 7},
                             { 0, 0,  0, 7, 0}};
        int i, j, n = 5;

        prims_algo(graph, n);

        cout << "The minimal spanning tree for the graph\n";
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++)
                        cout << graph[i][j] << "  ";
                cout << endl;
        }

        cout << endl;

        cout << "minimal spanning graph:\n";
        for (i = 0; i < n; i++){
                for (j = 0; j < n; j++)
                        cout << min_span[i][j] << "  ";
                cout << endl;
        }

        return 0;
}
