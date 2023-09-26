#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if(a <= 10) {
            if(b > mx) {
                ans = i + 1;
                mx = b;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}