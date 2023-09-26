#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(abs(H - x) % k == 0 && abs(H - x) / k < m && H != x) {++res; }
    }
    cout << res << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}