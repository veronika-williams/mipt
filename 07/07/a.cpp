#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    bool fl = true;
    for(int i = 0; i < n; ++i) {
        if(b[i] < a[i]) fl = false;
    }
    if(fl) {
        cout << 0 << endl;
        return ;
    }
    for(int i = 0; i < n; ++i) {
        int x = max(0LL, a[i] - b[i]); // height of sweet
        bool fl = true;
        for(int i = 0; i < n; ++i) {
            if(abs(a[i] - x) > b[i]) fl = false; 
        } 
        if(fl) {
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                cnt += (a[i] > b[i]);
            }
            cout << cnt << endl;
            return;
        }
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}