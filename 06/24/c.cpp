#include <bits/stdc++.h>
using namespace std;
#define int long long


inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    vector<int> mp(n + 1, 0), last(n + 1, -1);
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    last[a[0]] = 0;
    for(int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if(last[a[i]] != -1) {
            dp[i][1] = mp[a[i]] + i - last[a[i]] + 1;
        }
        if(dp[i][0] > mp[a[i]] + i - last[a[i]] || last[a[i]] == -1) {
            mp[a[i]] = dp[i][0];
            last[a[i]] = i;
        }
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
}  

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}