#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        if(x == i) ++cnt;
    }
    cout << (cnt + 1) / 2 << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}