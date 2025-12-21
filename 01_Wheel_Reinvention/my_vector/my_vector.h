#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stddef.h>

typedef struct {
    size_t size;
    size_t capacity;
    int* data;
} MyVector;

void vector_init(MyVector *v);
void vector_push_back(MyVector *v, int value);
int vector_get(MyVector *v, size_t index);
void vector_free(MyVector *v);

#endif