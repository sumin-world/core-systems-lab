#include <stdio.h>
#include <stdlib.h>

#include "my_vector.h"

int main() {
    MyVector v;

    // 1. Initialization
    printf("[Log] Vector Initializing..\n");
    vector_init(&v);

    // 2. Push
    // Stress Test (데이터 50개 삽입) - 용량이 늘어날 때마다 로그 찍어서 확인
    printf("[Log] Push Start (0~49)\n");
    for (int i = 0; i < 50; i++) {
        size_t old_cap = v.capacity;

        vector_push_back(&v, i * 10);

        if (v.capacity != old_cap) {
            printf(" -> Resize! %zu -> %zu (Size: %zu)\n", old_cap, v.capacity, v.size);
        }
    }

    // 3. Data Validation (데이터 검증)
    printf("[Log] Verifying Data...\n");

    for (int i = 0; i < 50; i++) {
        int val = vector_get(&v, i);

        if (val != i * 10) {
            fprintf(stderr, "[Error] Index %d: Expected %d, got %d\n", i, i * 10, val);
            return 1;
        }
    }
    printf("[Log] Data Verification Passed.\n");

    // 4. Teardown (메모리 해제)
    vector_free(&v);
    printf("[Log] Memory Freed. Exiting.\n");

    return 0;
}