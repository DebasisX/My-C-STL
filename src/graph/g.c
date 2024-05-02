#include "graph.h"
int main()
{
    // A simple implementation for the above.
    graph* x[3];
    int arr[5] = {6, 5, 3, 2, 1};
    int arr1[5] = {1, 1, 3, 2, 3};
    int arr2[5] = {9, 5, 7, 2, 5};
    x[0] = insert('S', 5, arr);
    x[1] = insert('W', 5, arr1);
    x[2] = insert('V', 5, arr2);
    printf("X is :%c \n", (char)x[1]->vertice);
    for (int i = 0; i < x[1]->num; i++)
    {
        printf("EDGE from X is :%d \n", x[1]->edges[i]);
    }
    printf("Running \n");
    freeG(x, 3);
    return 0;
}