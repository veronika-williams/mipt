#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, sm;
    cin >> x >> y;
    sm = x + y;
    vector<int> a(k);
    int fl = 0;
    for(int i = 0; i < k; ++i) {
        int o, u;
        cin >> o >> u;
        int t = o + u;
        if((t & 1) == (sm & 1)) fl = 1;
    }
    if(!fl) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}