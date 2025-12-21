#include "my_vector.h"

#include <stdio.h>
#include <stdlib.h>

void vector_init(MyVector *v) {
    v->size = 0;
    v->capacity = 0;
    v->data = NULL;
}

void vector_push_back(MyVector *v, int value) {
    int *temp = NULL;
    size_t new_capacity = 0;

    if(v->size == v->capacity) {
        if(v->capacity == 0) {
            v->capacity = 4;
            v->data = malloc(v->capacity * sizeof(int));
            if(v->data == NULL) {
                perror("malloc");
                exit(1);
            }
        } else {
            new_capacity = v->capacity * 2;
            temp = realloc(v->data, new_capacity * sizeof(int));
            if (temp == NULL) {
                perror("realloc");
                exit(1);
            } else {
                v->data = temp;
                v->capacity = new_capacity;
            }

        }
    }
    v->data[v->size] = value;
    v->size++;
}

int vector_get(MyVector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexOutBoundError: index %zu is out of bounds (sizeL %zu)\n", index, v->size);
        exit(1);
    }
    return v->data[index];
}

void vector_free(MyVector *v) {
    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}