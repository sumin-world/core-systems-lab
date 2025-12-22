/**
 * Problem: 백준 1000 - A+B
 * Link: https://www.acmicpc.net/problem/1000
 * Algorithm: Input/Output, Basic Arithmetic
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * Notes:
 * - C++ 기본 입출력 연습 문제.
 * - cin, cout 사용법과 main 함수 구조를 익힘.
 * - PS 문제의 최소 골격을 처음으로 경험한 문제.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cout << a+b << "\n";
    return 0;
}