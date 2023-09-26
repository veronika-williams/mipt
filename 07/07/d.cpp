#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> y(n);
    for(auto & i : y) cin >> i;
    int res = n * d * h;
    int mn = 0;
    for(int i = 0; i < n - 1; ++i) {
        if(y[i + 1] - y[i] < h) {
            int H = h - (y[i + 1] - y[i]);
            mn += H * H;
        }
    }

    cout << fixed << setprecision(10) << (res - (double) mn * d / h) * 0.5 << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}