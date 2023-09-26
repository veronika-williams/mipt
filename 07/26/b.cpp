#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    vector<int> odd, even;
    for(auto & i : a) {
        if(i % 2 == 0) {
            even.push_back(i);
        } else odd.push_back(i);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<int> res;
    int i = 0, j = 0;
    for(auto & x : a) {
        if(x % 2 == 0) {
            res.push_back(even[i++]);
        } else res.push_back(odd[j++]);
    }
    int fl = 1;
    for(int i = 0; i < n - 1; ++i) {
        if(res[i] > res[i + 1]) {
            cout << "NO\n";
            fl = 0;
            break;
        }
    }
    if(fl) cout << "YES\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}