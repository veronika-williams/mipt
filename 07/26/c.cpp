#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    if(a[0] == a[n-1]) {
        int cnt = 2;
        for(int i = 1; i < n - 1; ++i) {
            if(a[i] == a[0]) ++cnt;
        }
        if(cnt >= k) {
            cout << "YES\n";
        } else cout << "NO\n";
    } else {
        int cnt = 1;
        int pos = 1;
        for(;cnt < k && pos < n; ++pos) {
            if(a[pos] == a[0]) ++cnt;
        }
        if(cnt < k) {
            cout << "NO\n";
            return;
        }  
        cnt = 0;
        for(; cnt < k && pos < n; ++pos) {
            if(a[pos] == a[n - 1]) ++cnt;
        }
        if(cnt < k) {
            cout << "NO\n";
        } else cout << "YES\n";
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}