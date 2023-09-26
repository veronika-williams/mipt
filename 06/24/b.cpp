#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    for(auto & i : a) cin >> i;
    for(auto & i : b) cin >> i;
    for(auto & i : c) cin >> i;
    int A = 0, B = 0, C = 0;
    for(int i = 0; i < n; ++i) {
        if((A | a[i] | x) > x) break;
        A |= a[i];
    }
    for(int i =0 ; i < n; ++i) {
        if((B | b[i] | x) > x) break;
        B |= b[i];
    } 
    for(int i =0; i < n; ++i) {
        if((C | c[i] | x) > x) break;
        C |= c[i];
    }
    if((A | B | C) == x) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}