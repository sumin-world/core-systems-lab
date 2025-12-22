/**
 * Problem: 백준 10818 - 최소, 최대
 * Link: https://www.acmicpc.net/problem/10818
 * Algorithm: Brute Force (Single Pass)
 * Data Structure: vector<int> (또는 변수만 사용 가능)
 * Time Complexity: O(N)
 * Space Complexity: O(1) 또는 O(N)
 * Notes:
 * - 입력 크기 N만큼 한 번 순회하며 최소/최대 갱신.
 * - vector에 저장한 뒤 처리할 수도 있고,
 *   입력 받으면서 바로 처리하면 공간 O(1)로 최적화 가능.
 * - for문 1개 = O(N)이라는 시간복잡도 감각을 처음 체득한 문제.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int mn = a[0];
    int mx = a[0];
    
    for(int i = 1; i < n; i++) {
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }
    
    cout << mn << ' ' << mx << '\n';
    
}

// vector 없이, 시간복잡도는 똑같이 O(N), 공간은 더 적게 O(1)

/*

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x;
    cin >> x;
    int mn = x, mx = x;

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }

    cout << mn << ' ' << mx << '\n';
}

*/