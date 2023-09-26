#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    if(a[0] != 1) {
        cout << 1 << endl;
        return; 
    }
    int cur = 1;
    for(auto& i : a) {
        i -= cur;
        ++cur;
    }
    int j = 0;
    int total = 0;
    for(int i = 0; i < k; ++i) {
        while(j + 1 < n && a[j + 1] <= total) ++j;
        total += j + 1;
    }
    cout << total + 1 << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}