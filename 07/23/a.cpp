#include<bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    int mn = 100000000000;
    for(int i= 0; i < n - 1; ++i) {
        mn = min(mn, a[i + 1] - a[i]);
    }
    if(mn < 0) {
        cout << 0 << endl;
    } else cout << mn / 2 + 1 << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}