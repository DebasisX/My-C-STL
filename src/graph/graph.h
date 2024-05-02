#pragma clang diagnostic ignored "-Wint-conversion"   // Silencing warnings from clang. Lol!
#pragma clang diagnostic ignored "-Wvoid-pointer-to-int-cast"
#pragma clang diagnostic ignored "-Warray-bounds"

#include <stdio.h>
#include <stdlib.h>
// To be used by someone who has some expertise with memory allocation and graphs.
typedef struct graph 
{
    int id; // ID for the vertice.
    void* vertice; // Can be turned to store int, char, string.
    int num; // No. of edges.
    int *edges; // Pointer to the array of edges.
} graph;

graph* insert(int id, void* vertice, int num, int arr[]) // Pass in Vertice can be Character, Integer, String or any Custom Data Type 
// along with no. of edges and array to which it would be connected.
{
    graph* x = (graph*)malloc(sizeof(graph));  // Allocating space. May crash on undefined structures.
    x->vertice = vertice; // Storing the vertice.
    x->id = id;
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
