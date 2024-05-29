
#include<stdio.h>

// Number of vertices in the graph
#define V 5

void printSolution(int path[]);

int isSafe(int v, int graph[V][V], int path[], int pos)
{
    if (graph [ path[pos-1] ][ v ] == 0)
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

int hamCycleUtil(int graph[V][V], int path[], int pos)
{
    if (pos == V)
    {
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return 1;
        else
          return 0;
    }

    for (int v = 1; v < V; v++)
    {
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            /* recur to construct rest of the path */
            if (hamCycleUtil (graph, path, pos+1) == 1)
                return 1;

            /* If adding vertex v doesn't lead to a solution,
               then remove it */
            path[pos] = -1;
        }
    }

    
    return 0;
}

int hamCycle(int graph[V][V])
{
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == 0 )
    {
        printf("\nSolution does not exist");
        return 0;
    }

    printSolution(path);
    return 1;
}

/* A utility function to print solution */
void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);

    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}

// driver program to test above function
int main()
{
    int graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };

    // Print the solution
    hamCycle(graph1);

   int graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };

    // Print the solution
    hamCycle(graph2);

    return 0;
}
