/**
 * Problem: 백준 12813 - 이진수 연산
 * Link: https://www.acmicpc.net/problem/12813
 * Algorithm: String Parsing, Bitwise Logic Simulation
 * Data Structure: string
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * Notes:
 * - 이진수 길이가 최대 100,000이라 정수형으로 처리 불가능.
 * - 각 자릿수를 string 인덱스로 접근하여 직접 연산.
 * - AND, OR, XOR, NOT 연산을 조건문으로 구현.
 * - 결과는 한 자리씩 누적하므로 += 사용.
 * - 자리별 연산 문제 → for문 + 인덱스 접근 패턴 학습.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    int n = A.size();

    string AND = "", OR = "", XOR = "", NOTA = "", NOTB = "";

    for(int i = 0; i < n; i++) {
        // AND
        if (A[i] == '1' && B[i] == '1') AND += '1';
        else AND += '0';

        // OR
        if (A[i] == '1' || B[i] == '1') OR += '1';
        else OR += '0';

        // XOR
        if (A[i] != B[i]) XOR += '1';
        else XOR += '0';

        // NOTA, NOTB
        NOTA += (A[i] == '1' ? '0' : '1');
        NOTB += (B[i] == '1' ? '0' : '1');
    }

    cout << AND << '\n';
    cout << OR << '\n';
    cout << XOR << '\n';
    cout << NOTA << '\n';
    cout << NOTB << '\n';
}