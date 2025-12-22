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