#include <stdio.h>
#include <time.h>

#define ROW 10000
#define COL 10000

// 엄청 큰 2차원 배열 선언 (약 400MB)
// 힙이나 전역에 잡아야 스택 오버플로우 안 남
int arr[ROW][COL];

int main() {
    clock_t start, end;

    // -------------------------------------------------
    // CASE 1. 착한 접근 (Cache Hit)
    // 메모리에 저장된 순서대로 읽음 (가로 -> 세로)
    // -------------------------------------------------
    start = clock();
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = 1; // 행(i) 고정, 열(j) 이동
        }
    }
    end = clock();
    printf("CASE 1 (Good): %lf sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    // -------------------------------------------------
    // CASE 2. 나쁜 접근 (Cache Miss 폭발)
    // 메모리 여기저기 점프하며 읽음 (세로 -> 세로)
    // -------------------------------------------------
    start = clock();
    for (int j = 0; j < COL; j++) {
        for (int i = 0; i < ROW; i++) {
            arr[i][j] = 1; // 열(j) 고정, 행(i) 이동 <-- 원인!!
        }
    }
    end = clock();
    printf("CASE 2 (Bad): %lf sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}