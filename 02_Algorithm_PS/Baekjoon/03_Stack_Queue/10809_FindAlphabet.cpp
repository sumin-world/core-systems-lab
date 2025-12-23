/**
 * Problem: 백준 10809 - 알파벳 찾기
 * Link: https://www.acmicpc.net/problem/10809
 * Algorithm: Brute Force (모든 알파벳에 대해 검색)
 * Data Structure: String (STL)
 * Time Complexity: O(N) (엄밀히는 26 * N이지만 상수는 무시)
 * Space Complexity: O(N) (문자열 저장 공간)
 * Notes:
 * - string::find()를 사용해 특정 문자의 첫 위치를 찾음
 * - 못 찾으면 string::npos를 반환한다는 점을 활용
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for(char c = 'a'; c <= 'z'; c++) {
        size_t pos = s.find(c);
        if(pos != string::npos) {
            cout << pos << " ";
        } else {
            cout << -1 << " ";
        }
    }
    return 0;
}