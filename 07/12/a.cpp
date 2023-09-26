#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    int ans = 0;
    vector<int> del;
    for(int i = 0; i < n - 1; ++i) {
        del.push_back(abs(a[i] - a[i + 1]));
        ans += abs(a[i] - a[i + 1]);
    }
    sort(del.begin(), del.end());
    reverse(del.begin(), del.end());
    for(int i = 0; i < k - 1; ++i) ans -= del[i];
    cout << ans << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}