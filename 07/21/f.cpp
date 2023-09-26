#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    vector<int> cnt(n + 1, 0);
    for(auto & i : a){ 
        if(i <= n) ++cnt[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int cur = 0;
        for(int j = 1; j * j <= i; ++j) {
            if(i % j == 0) {
                cur += cnt[j];
                if(j * j != i) cur += cnt[i / j];
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}