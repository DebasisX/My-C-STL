#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_init(vector* v, vec_type type) {
    v->sz = 0;
    v->cap = 16;  // larger to reduce reallocations
    v->type = type;

    switch (type) {
        case TYPE_INT:
            v->size = sizeof(int);
            v->insert_func = asm_insint;
            v->delete_func = asm_deli;
            v->search_func = asm_srchi;
            v->index_func = asm_idxi;
            break;
        case TYPE_STRING:
            v->size = sizeof(char*);
            v->insert_func = asm_insstr;
            v->delete_func = asm_dels;
            v->search_func = asm_srchs;
            v->index_func = asm_idxs;
            break;
        case TYPE_DOUBLE:
            v->size = sizeof(double);
            v->insert_func = asm_insd;
            v->delete_func = asm_deld;
            v->search_func = asm_srchd;
            v->index_func = asm_idxd;
            break;
        default:
            printf("type?!\n");
            exit(1);
    }

    v->data = malloc(v->cap * v->size);
    if (!v->data) {
        printf("malloc...\n");
        exit(1);
    }
}
void vector_free(vector* v) {
    free(v->data);
    v->data = NULL;
    v->sz = 0;
    v->cap = 0;
}
void vector_ins(vector* v, void* value) {
    if (v->sz == v->cap) {
        v->cap *= 2;
        void* new_data = realloc(v->data, v->cap * v->size);
        if (!new_data) {
            printf("realloc...\n");
            exit(1);
        }
        v->data = new_data;
    }
    v->insert_func(v, value);
    v->sz++;
}

void vector_del(vector* v, int index) {
    if (index < 0 || (size_t)index >= v->sz) 
    	return;
    v->delete_func(v, index);
    v->sz--;
}

int vector_srch(vector* v, void* value) {
    return v->search_func(v, value);
}

void vector_get(vector* v, int index, void* out) {
    if (index < 0 || (size_t)index >= v->sz) 
    	return;
    v->index_func(v, index, out);
}
