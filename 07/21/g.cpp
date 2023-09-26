#include<bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    map<int, int> a, b, c, d;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
        c[x + y]++;
        d[x - y + 2000000000]++;
    }
    int res = 0;
    for(auto & [key, val] : a) {
        res += val * (val - 1);
    }
    for(auto & [key, val] : b) {
        res += val * (val - 1);
    }
    for(auto & [key, val] : c) {
        res += val * (val - 1);
    }
    for(auto & [key, val] : d) {
        res += val * (val - 1);
    }
    cout << res << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}