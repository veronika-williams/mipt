#include<bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a = {1, 1};
    int m = 2;
    while(1) {
        a.push_back(a[m-1] + a[m - 2]);
        ++m;
        if(a[m-1] > n) break;
    }
    if(k > m) {
        cout << 0 << endl;
        return;
    }
    int x = a[k-3], y = a[k-2];
    int res = 0;
    for(int f1 = 0; n - x * f1 >= 0; ++f1) {
        if((n - x * f1) % y == 0) {
            int f2 = (n - x * f1) / y;
            if(f2 < f1) break;
            ++res;
        }
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}