#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    int maxval = 256;
    vector<int> pref(maxval, 0);
    pref[0] = 1;

    int cur = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        cur ^= a[i];
        for(int p = 0; p < maxval; ++p) {
            if(pref[p]) {
                ans = max(ans, p ^ cur);
            }
        }
        pref[cur] = 1;
    }
    cout << ans << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}