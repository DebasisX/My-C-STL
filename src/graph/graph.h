#pragma clang diagnostic ignored "-Weverything"   // Silencing warnings from clang. Lol!


#include <stdbool.h>
#include <limits.h>
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
int *arr;
int initial = 0;
void alloc_visited(int n)
{  
    arr = malloc(sizeof(int) * n);
}
void dealloc_visited()
{
  free(arr);
}

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

void dfs(graph** x, int num, int id) // Don't try to understand, it was pure instinct as I have never looked at generalised algorithms
// these algorithms are made by me without reference so ignore if there is something off but be sure it gets the job done correctly. 
{
    int total = 0;
    for(int i = 0; i < num; i++)
    {
        total += x[i]->num;
    }
    int visited[num][total];
    for (int i = 0; i < num; i++) {
    for (int j = 0; j < total; j++) {
        visited[i][j] = 0;
        }
    }
    
    for(int i = 0; i < num; i++) // index of vertice
    {
        for(int j = 0; j < x[i]->num; j++) // edges
        { // If already in the array just say cycle is present and terminate.
            if (x[i]->id == id){
                visited[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < num; i++) // index of vertice
    {
        for(int j = 0; j < x[i]->num; j++) // edges
        {
            if (visited[i][j] == 1)
            {
                printf("Vertice ID from %d to %d visited = %d. \n", x[i]->id, x[i]->edges[j], visited[i][j]);
                arr[initial] = x[i]->id; 
                initial++;
            }
        }
    }
    for(int i = 0; i < num; i++) // index of vertice
    {
        for(int j = 0; j < x[i]->num; j++) // edges
        {
            if (visited[i][j] == 1)
            {
                id = x[i]->edges[j];
                int z = 0;
                for(int temp = 0; temp < initial; temp++)
                {
                    if (arr[temp] == id)
                    {
                        z++;
                    }
                } 
                if(z == 0)
                {
                    arr[initial] = x[i]->edges[j];
                    initial++;
                    dfs(x, num, id);
                }
            }
        }  
    }
}
int cyclic(graph** x, int num, int id) // Don't try to understand, it was pure instinct as I have never looked at generalised algorithms
// these algorithms are made by me without reference so ignore if there is something off but be sure it gets the job done correctly.
{     
  int total = 0;     
  for(int i = 0; i < num; i++)     
  {
    total += x[i]->num;     
  }     
  int visited[num][total];     
  for (int i = 0; i < num; i++) 
  {     
    for (int j = 0; j < total; j++) 
    {                 
        visited[i][j] = 0;              // Assignning the visited array with 0's 
                          
    }     
  }         
  for(int i = 0; i < num; i++) // index of vertice    
  {         
    for(int j = 0; j < x[i]->num; j++) // edges  
    {                         
      if (x[i]->id == id)
      {             
        visited[i][j] = 1;             // Assignning the visited array with 1 where the ID is same.
      }                     
    }
  }     
  for(int i = 0; i < num; i++) // index of vertice   
  {   
    for(int temp = 0; temp < initial; temp++) 
    {
      if (arr[temp] == x[i]->id)
      {
        printf("ID: %d  ARR[TEMP]: %d\n", id, arr[temp]);
        return id;
      }
    }
    for(int j = 0; j < x[i]->num; j++) // edges    
        {             
          if (visited[i][j] == 1)             
          {
                          
              arr[initial] = x[i]->id;
              initial++;
          }
        }
    }
  
      
  for(int i = 0; i < num; i++) // index of vertice    
  {         
    for(int j = 0; j < x[i]->num; j++) // edges   
    {             
      if (visited[i][j] == 1)             
      {                 
        id = x[i]->edges[j];                 
        int z = 0;                 
        for(int temp = 0; temp < initial; temp++)                 
        {                     
          if (arr[temp] == id)                     
          {                         
            z++;                     
          }                 
        }                 
        if(z == 0)                 
        {                     
          arr[initial] = x[i]->edges[j];                    
          initial++;                     
          int y = cyclic(x, num, id);                     
          return y; // It is not cyclic. False.
        }
      }
    }
  }
}
void dijkstra(graph **x, int num, int sourc, int dest)
{
  // Final Function for this Library.
}