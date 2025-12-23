/**
 * Problem: 백준 11720 - 숫자의 합
 * Link: https://www.acmicpc.net/problem/11720
 * Algorithm: 문자열 순회 + 아스키 코드 변환
 * Data Structure: String
 * Time Complexity: O(N) - 문자열 길이만큼 순회
 * Space Complexity: O(N) - 문자열 저장
 * Notes:
 * - 숫자가 100자리까지 가능해서 int/long long 불가
 * - string으로 받아서 한 글자씩 처리
 * - 문자 '0'~'9'를 숫자 0~9로 변환: c - '0'
 * - C++에서 지역변수 항상 초기화, 안 하면 랜덤값(쓰레기값)이 들어감
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int sum = 0;

    for(char c : s) {
        sum += c - '0';
    }
    
    cout << sum << '\n';
    
    return 0;
}