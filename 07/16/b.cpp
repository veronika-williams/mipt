#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> b(k);
    vector<int> last(k, -1);
    for(auto & i : a) cin >> i;
    
    for(int i = 0; i < n; ++i) {
        b[a[i] - 1].push_back(i - last[a[i] - 1] - 1);
        last[a[i] - 1] = i;
    }

    for(int i = 0; i < k; ++i) {
        b[i].push_back(n - last[i] - 1);
        sort(b[i].begin(), b[i].end());
        // for(auto & x : b[i]) cout << x << ' ';
        // cout << endl;
    }
    
    int mn = n;
    for(int i = 0; i < k; ++i) {
        int cur = n;
        if(!b[i].empty()) cur = b[i].back() / 2;
        if(b[i].size() > 1) cur = max(cur, b[i][b[i].size() - 2]);
        mn = min(mn, cur);
    }
    cout << mn << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}