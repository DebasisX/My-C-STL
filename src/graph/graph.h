#include <stdio.h>
#include <stdlib.h>
// To be used by someone who has some expertise with memory allocation and graphs.
typedef struct graph 
{
    void* vertice; // Can be turned to store int, char, string.
    int num; // No. of edges.
    int *edges; // Pointer to the array of edges.
} graph;

graph* insert(void* vertice, int num, int arr[]) // Pass in Vertice can be Character, Integer, String or any Custom Data Type 
// along with no. of edges and array to which it would be connected.
{
    graph* x = (graph*)malloc(sizeof(graph));  // Allocating space. May crash on undefined structures.
    x->vertice = vertice; // Storing the vertice.
    x->num = num; // No. of edges to allocate space to.
    x->edges = (int*)malloc(sizeof(int) * num); // Allocating space for edges.
    for (int i = 0; i < num; i++)
    {
        x->edges[i] = arr[i]; // Storing the edges from input array to our graph.
    }
    return x; // Returning the pointer to the graph.
}
void freeG(graph* x[], int edges) // Pass in pointer to graph and no. of edges to clear, i.e, x->num.
{
    for (int i = 0; i < edges; i++)
    {
        free(x[i]->edges);
        free(x[i]);
    }
    // All memory will be freed including the pointer to the graph.
}

// int main()
// {
//     // A simple implementation for the above.
//     graph* x[2];
//     int arr[5] = {6, 5, 3, 2, 1};
//     int arr1[5] = {1, 1, 3, 2, 3};
//     int arr2[5] = {9, 5, 7, 2, 5};
//     x[0] = insert('S', 5, arr);
//     x[1] = insert('W', 5, arr1);
//     x[2] = insert('V', 5, arr2);
//     printf("X is :%c \n", (char)x[1]->vertice);
//     for (int i = 0; i < x[1]->num; i++)
//     {
//         printf("EDGE from X is :%d \n", x[1]->edges[i]);
//     }
//     freeG(x, 3);
//     return 0;
// }