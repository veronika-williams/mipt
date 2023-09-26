#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    sort(a.begin(), a.end());
    int mx = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[j] - a[j - 1] > k || j == n - 1) {
                mx = max(mx, j - i + (j == n - 1 && (a[j] - a[j - 1] <= k)));
                i = j - 1;
                break;
            }
        }
    }
    cout << n - mx << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}