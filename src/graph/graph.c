#include "graph.h"
int main()
{
    // A simple implementation for the above.
    graph* x[3];
    int arr0[2] = {14, 27};
    int arr1[1] = {14};
    int arr2[1] = {56};
    x[0] = insert(56, 'A', 2, arr0);
    x[1] = insert(27, 'B', 1, arr1);
    x[2] = insert(14, 'C', 1, arr2);
    
    for (int j = 0; j < 3; j++)
    { 
        // Displaying.
        printf("X is :%c \n", (char)x[j]->vertice);
        for (int i = 0; i < x[j]->num; i++)
        {
            printf("EDGE from X is :%d \n", x[j]->edges[i]);
        }
    }
    freeG(x, 3);
    return 0;
}