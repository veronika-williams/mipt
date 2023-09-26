#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    bool fl = 1;
    for(auto & i : a) {
        if(i > 0) fl = 0;
    }
    if(fl) {
        int mx = a[0];
        for(auto & i : a) mx = max(mx, i);
        cout << mx << "\n";
        return;
    }
    int a1 = 0, a2 = 0;
    for(int i = 0; i < n; ++i) {
        if(i & 1) a1 += max(0LL, a[i]);
        else a2 += max(0LL, a[i]);
    }
    cout << max(a1, a2) << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}