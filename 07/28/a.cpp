#include<bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int b, c, h;
    cin >> b >> c >> h;
    cout << min(2 * b - 1, 2 * (c + h) + 1) << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}