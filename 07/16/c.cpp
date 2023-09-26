#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    int x = 0, y = 0, z = 0;
    for(int i = 0; i < n; ++i) {
        int g = gcd(a[i], b[i]);
        if(g != 0) {
            a[i] /= g;
            b[i] /= g;
        }
        if((a[i] & 1) && !(b[i] & 1)) x = 1;
        if(!(a[i] & 1) && (b[i] & 1)) y = 1;
        if((a[i] & 1) && (b[i] & 1)) z = 1;
    }
    if(x + y + z <= 1) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}