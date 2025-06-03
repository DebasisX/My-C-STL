#include <stdio.h>
#include <stdlib.h>

#define N 5000000

int main() {
    size_t capacity = 16;
    size_t size = 0;
    int* arr = malloc(capacity * sizeof(int));
    if (!arr) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (size_t i = 0; i < N; i++) {
        if (size == capacity) {
            capacity *= 2;
            int* tmp = realloc(arr, capacity * sizeof(int));
            if (!tmp) {
                perror("realloc");
                free(arr);
                return 1;
            }
            arr = tmp;
        }
        arr[size++] = (int)i;
    }

    printf("std last = %d\n", arr[N - 1]);

    free(arr);
    return 0;
}
