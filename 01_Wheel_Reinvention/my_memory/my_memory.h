#ifndef MY_MEMORY_H
#define MY_MEMORY_H

#include <stddef.h>
// dest: 복사 받을 곳 주소
// src: 복사할 원본 주소
// n: 복사할 바이트 수
// 반환값: dest의 시작 주소
void *my_memcpy(void *dest, const void *src, size_t n);

#endif