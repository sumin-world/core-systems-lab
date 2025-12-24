/**
 * Problem: 백준 2675 - 문자열 반복
 * Link: https://www.acmicpc.net/problem/2675
 * Algorithm: Nested Loop (이중 반복문)
 * Data Structure: String
 * Time Complexity: O(T × |S| × R) - T개 테스트, 각 문자열 길이 |S|, R번 반복
 * Space Complexity: O(|S|) - 문자열 저장 공간
 * Notes:
 * - 문자열의 각 문자를 R번씩 반복 출력
 * - 이중 for문: 바깥(문자 순회) × 안쪽(R번 반복)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int r;
        string s;
        cin >> r >> s;
        
        // 각 문자에 대해
        for(int j = 0; j < s.length(); j++) {
            // R번 반복 출력
            for(int k = 0; k < r; k++) {
                cout << s[j];
            }
        }
        cout << "\n";
    }
    
    return 0;
}