#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, m;
    cin >> n >> m;
    int a = 0, b = 0;
    for(int i =0; i < n; ++i) {
        int x;
        cin >> x;
        a += x;
    }
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b += x;
    }
    if(a > b) {
        cout << "Tsondu\n";
    } else if(a == b) {
        cout << "Draw\n";
    } else {
        cout << "Tenzing\n";
    }
} 

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}