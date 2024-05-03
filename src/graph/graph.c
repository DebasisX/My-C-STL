#include "graph.h"
#include <stdio.h>

int main() {
    // A simple implementation for the above.
    graph* x[5];
    int arr0[2] = {27, 14};
    int arr1[2] = {14, 18};
    int arr2[4] = {56, 27, 18, 21};
    int arr3[2] = {21, 56};
    int arr4[1] = {18};
    x[0] = insert(56, 'A', 2, arr0);
    x[1] = insert(27, 'B', 2, arr1);
    x[2] = insert(14, 'C', 4, arr2);
    x[3] = insert(18, 'D', 2, arr3);
    x[4] = insert(21, 'E', 1, arr4);
    alloc_visited(5);
    dfs(x, 5, 27);
    freeG(x, 5);
    return 0;
}


