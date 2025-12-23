/**
 * Problem: 백준 2751 - 수 정렬하기 2
 * Link: https://www.acmicpc.net/problem/2751
 * Algorithm: STL sort() - Intro Sort (Quick Sort + Heap Sort + Insertion Sort 하이브리드)
 * Data Structure: Vector (동적 배열)
 * Time Complexity: O(N log N) - sort() 함수의 시간복잡도
 * Space Complexity: O(N) - N개의 정수를 저장하는 벡터
 * Notes:
 * - sort()는 C++ STL에서 제공하는 최적화된 정렬 함수
 * - 출력 시 endl 대신 "\n" 사용 (버퍼 flush 방지로 속도 향상)
 * - N이 최대 1,000,000이므로 O(N²) 정렬(버블/선택)은 시간 초과
 */
 #include <bits/stdc++.h>
 using namespace std;

int main() {
    // 입출력 속도 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;  // 수의 개수
    
    // N개의 정수를 저장할 벡터 선언
    vector<int> v(n);
    
    // 입력: O(N)
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // 정렬: O(N log N) ← 여기가 핵심!
    sort(v.begin(), v.end());
    
    // 출력: O(N)
    // Range-based for로 간결하게 작성
    for(int x: v) {
        cout << x << "\n";  // endl 대신 \n
    }
    
    return 0;
}