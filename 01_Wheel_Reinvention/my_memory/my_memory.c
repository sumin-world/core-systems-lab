#include "my_memory.h"

void *my_memcpy(void *dest, const void *src, size_t n) {
    char *c_dest = (char *)dest;
    const char *c_src = (const char *)src;

    for(size_t i = 0; i < n; i++) {
        c_dest[i] = c_src[i];
    }
    return dest;
}