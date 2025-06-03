#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef enum {
    TYPE_INT = 1,
    TYPE_STRING,
    TYPE_DOUBLE
} vec_type;

// fp for direct call;
typedef void (*ins)(void*, void*);
typedef void (*del)(void*, int);
typedef int (*srch)(void*, void*);
typedef void (*idx)(void*, int, void*);

typedef struct {
    void*    data;
    size_t   sz; // size
    size_t   cap;
    vec_type type;
    size_t   size; // element size
    
    // fp for ASM routines
    ins insert_func;
    del delete_func;
    srch search_func;
    idx index_func;
} vector;

void vector_init(vector* v, vec_type type);
void vector_free(vector* v);
void vector_ins(vector* v, void* value);
void vector_del(vector* v, int index);
int vector_srch(vector* v, void* value);
void vector_get(vector* v, int index, void* out);

extern void asm_insint(void* v, void* value);
extern void asm_insd(void* v, void* value);
extern void asm_insstr(void* v, void* value);

extern void asm_deli(void* v, int index);
extern void asm_deld(void* v, int index);
extern void asm_dels(void* v, int index);

extern int asm_srchi(void* v, void* value);
extern int asm_srchd(void* v, void* value);
extern int asm_srchs(void* v, void* value);
extern void asm_idxi(void* v, int index, void* out);
extern void asm_idxd(void* v, int index, void* out);
extern void asm_idxs(void* v, int index, void* out);
#endif
