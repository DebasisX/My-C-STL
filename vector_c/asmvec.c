#include "vector.h"
#include <stdio.h>
#include <time.h>

#define N 5000000

int main() {
    vector v;
    vector_init(&v, TYPE_INT);

    for (int i = 0; i < N; i++) {
        vector_ins(&v, &i);   // renamed from vector_insert to vector_ins
        // still facing a conflict, linked-list was named vector_insert......!!!
    }

    int last;
    vector_get(&v, N - 1, &last); // yeah working
    printf("asm last = %d\n", last);

    vector_free(&v);
    return 0;
}
