/**
 * Problem: 백준 30389 - Suffi⊗
 * Link: https://www.acmicpc.net/problem/30389
 * Algorithm: 정렬 + 홀짝 카운팅 (XOR의 수학적 성질 활용)
 * Data Structure: vector<string>
 * Time Complexity: O(T log T) where T = 총 접미사 개수
 * Space Complexity: O(T)
 * Notes:
 * - XOR의 핵심: 짝수 번 등장 → 상쇄, 홀수 번 등장 → 생존
 * - 모든 접미사를 모아서 정렬 → 같은 것끼리 연속 배치
 * - 연속된 개수 세고 홀수인 것만 카운팅
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> all_suffixes;
    
    // 1. 모든 문자열의 모든 접미사 수집
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        // s의 모든 접미사 생성
        for(int j = 0; j < s.length(); j++) {
            all_suffixes.push_back(s.substr(j));
        }
    }
    
    // 2. 정렬 (같은 문자열끼리 연속되게)
    sort(all_suffixes.begin(), all_suffixes.end());
    
    // 3. 연속된 개수 세기 (Two-Pointer)
    int ans = 0;
    int count = 1;  // 첫 원소부터 시작
    
    for(int i = 1; i < all_suffixes.size(); i++) {
        if (all_suffixes[i] == all_suffixes[i-1]) {
            count++;  // 같은 문자열 계속
        } else {
            // 다른 문자열 나옴 → 이전 그룹 정산
            if (count % 2 == 1) ans++;  // 홀수면 생존
            count = 1;  // 새 그룹 시작
        }
    }
    
    // 4. 마지막 그룹 처리 (필수!)
    if (count % 2 == 1) ans++;
    
    cout << ans << "\n";
    
    return 0;
}