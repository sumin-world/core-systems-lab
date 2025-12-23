/**
 * Problem: 백준 10871 - X보다 작은 수
 * Link: https://www.acmicpc.net/problem/10871
 * Algorithm: 선형 탐색 (Linear Search) / 조건 필터링
 * Data Structure: Vector (동적 배열)
 * Time Complexity: O(N) - N개의 원소를 한 번씩 순회
 * Space Complexity: O(N) - N개의 정수를 저장하는 벡터
 * Notes:
 * - 문제 조건: X보다 작은 수를 입력받은 순서대로 출력
 * - 접근법: 배열에 저장 후 조건에 맞는 원소만 필터링하여 출력
 * - 핵심: 입력과 동시에 출력도 가능하지만, 배열 연습을 위해 벡터 사용
 * - 배운 점: Range-based for loop으로 코드를 더 간결하게 작성 가능
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 입출력 속도 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 1. 변수 선언 및 입력
    int n, x;
    cin >> n >> x;  // n: 수열의 크기, x: 비교 기준값

    // 2. 크기가 n인 벡터 'a' 선언 (모든 원소 0으로 초기화됨)
    vector<int> a(n);

    // 3. 반복문으로 n개의 숫자를 vector 'a'에 입력받기
    for(int i = 0; i < n; i++) {
        cin >> a[i];  // i번째 원소에 입력값 저장
    }

    // 4. 결과 출력 - x보다 작은 수만 출력
    for(int i = 0; i < n; i++) {
        if (a[i] < x) {
            cout << a[i] << " ";  // 공백으로 구분하여 출력
        }
    }

    // 5. 마지막 줄바꿈 (출력 형식 맞추기)
    cout << "\n";

    return 0;
}

/* ========================================
 * 코드 개선 (Refine)
 * ========================================
 * 
 * Range-based for loop 활용
 * - 인덱스(i)가 굳이 필요 없는 경우 더 간결한 코드 작성 가능
 * - 가독성 향상 및 인덱스 관련 실수 방지
 */

// [방법 1] 인덱스 기반 for문 - 인덱스 정보가 필요할 때 사용
for(int i = 0; i < n; i++) {
    if(a[i] < x) cout << a[i] << " ";
}

// [방법 2] Range-based for문 - 값만 필요할 때 사용 (더 간결)
// val에 a의 각 원소가 순서대로 복사됨
for(int val : a) {
    if (val < x) cout << val << " ";
}

/* ========================================
 * 추가 최적화 방안
 * ========================================
 * 
 * [메모리 절약형] 입력과 동시에 출력 - O(1) 공간복잡도
 * 배열에 저장하지 않고 입력받으면서 바로 처리
 */
/*
int n, x;
cin >> n >> x;

for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if(num < x) cout << num << " ";
}
cout << "\n";
*/

/* ========================================
 * Range-based for 참조 사용법 정리
 * ========================================
 * 
 * 1. 값 복사 (기본)
 *    for(int val : a) { }
 *    - 원본 수정 불가
 *    - 작은 타입(int, char)에 적합
 * 
 * 2. 참조 (수정 가능)
 *    for(int& val : a) { }
 *    - 원본 직접 수정 가능
 *    - 입력받을 때 사용
 * 
 * 3. const 참조 (읽기 전용, 최적화)
 *    for(const int& val : a) { }
 *    - 복사 비용 없음
 *    - 원본 수정 불가 (실수 방지)
 *    - 큰 객체(string, vector)에 적합
 */