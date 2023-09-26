#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &  i : a) cin >> i;
    vector<int> v(32);
    for(auto & x : a) {
        for(int i = 0; i < 32; ++i) {
            if(!(x & (1 << i))) ++v[i];
        }
    }
    int mn = 1000000000;
    for(auto & i : v) if(i != 0) mn = min(mn, i);
    cout << "v: ";
    for(auto & i : v) cout << i << ' ';
    cout << endl;
    cout << mn << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}