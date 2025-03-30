#include "graph.h"
#include <stdio.h>


int main() {
    graph* x[5];
    int arr0[1] = {27};
    int arr1[1] = {14};
    int arr2[4] = {56, 27, 18, 21};
    int arr3[2] = {21, 14};
    int arr4[1] = {18};
    x[0] = insert(56, 'A', 1, arr0);
    x[1] = insert(27, 'B', 1, arr1);
    x[2] = insert(14, 'C', 4, arr2);
    x[3] = insert(18, 'D', 2, arr3);
    x[4] = insert(21, 'E', 1, arr4);
    alloc_visited(5);
    dfs(x, 5, 21);
    dealloc_visited();
    alloc_visited(5);

    int y1 = cyclic(x, 5, 14);
    printf("0 means Not-Cyclic, 1 means Cyclic.\nReturn Value is: %d\n", y1);
    dealloc_visited();
    
    // Dijkstra's Algorithm Usage
    int source = 56;
    int* shortestPaths = dijkstra(x, 5, source);
    if (shortestPaths) {
        printf("Shortest paths from %d:\n", source);
        for (int i = 0; i < 5; i++) {
            printf("To %d: %d\n", x[i]->id, shortestPaths[i]);
        }
        free(shortestPaths);
    }
    
    freeG(x, 5);
    
    graph *x1[2];
    int arr5[1] = {27};
    int arr6[1] = {56};
    x1[0] = insert(56, 'A', 1, arr5);
    x1[1] = insert(27, 'B', 1, arr6);
    alloc_visited(2);
    int y = cyclic(x1, 2, 27);
    printf("0 means Not-Cyclic, 1 means Cyclic.\nReturn Value is: %d\n", y);
    dealloc_visited();
    freeG(x1, 2);
    
    return 0;
}
