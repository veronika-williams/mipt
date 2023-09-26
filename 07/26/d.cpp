#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n-1);
    for(auto & i : a) cin >> i;
    vector<int> used(n + 1, 0);
    int mist = -1;
    if(a[0] > n) mist = a[0];
    else used[a[0]] = 1;
    for(int i = 0; i < n - 2; ++i) {
        int x = a[i + 1] - a[i];
        if(x > n || used[x]) {
            if(mist == -1) mist = x;
            else {
                cout << "NO\n";
                return;
            }
        } else used[x] = 1;
    }

    if(mist == -1) {
        cout << "YES\n";
        return;
    }
    
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) mist -= i;
    }
    if(mist == 0) cout << "YES\n";
    else cout << "NO\n";
    return;
    
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}