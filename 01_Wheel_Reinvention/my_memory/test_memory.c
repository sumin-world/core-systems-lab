#include <stdio.h>
#include <string.h>
#include "my_memory.h"

// Case C를 위한 구조체 정의
struct Student {
    int id;
    int score;
};

int main(void) {
    // Case A: int 배열 복사

    // 1. 원본 배열 선언 및 초기화
    int src[] = {1, 2, 3};

    // 2. 목적지 배열 선언
    int dest[3];

    // 3. my_memcpy 호출
    my_memcpy(dest, src, 3 * sizeof(int));

    // 4. 결과 출력
    printf("Case A - int array:\n");
    for(int i = 0; i < 3; i++) {
        printf("dest[%d] = %d\n", i, dest[i]);
    }
    printf("\n");

    // Case B: 문자열 복사

    // 1. 원본 문자열
    char s1[] = "Google";

    // 2. 목적지 배열
    char s2[10];

    // 3. my_memcpy 호출
    my_memcpy(s2, s1, strlen("Google") + 1);

    // 4. 결과 출력
    printf("Case B - string:\n");
    printf("s2 = %s\n", s2);

    // Case C: 구조체 복사

    // 1. 원본 구조체
    struct Student a = {20241234, 100};

    // 2. 목적지 구조체
    struct Student b;

    // 3. my_memcpy 호출 - 주소 전달 주의
    my_memcpy(&b, &a, sizeof(struct Student));

    // 4. 결과 출력
    printf("Case C - struct:\n");
    printf("a.id = %d, a.score = %d\n", a.id, a.score);
    printf("b.id = %d, b.score = %d\n", b.id, b.score);
    printf("\n");

    return 0;
}