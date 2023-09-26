#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        ++res;
        if(a[i] == 0) {
            if(i + 1 < n && a[i + 1] != 0) {
                int j = i + 1;
                int fl = 0;
                if(a[j] == 2) fl = 1;
                while(j + 1 < n && a[j + 1] != 0) {
                    ++j;
                    if(a[j] == 2) fl = 1;
                }
                if(fl) {
                    ++j;
                }
                i = j;
            }
        } else {
            int j = i;
            while(j + 1 < n && a[j + 1] != 0) ++j;
            ++j;
            i = j;
        }
    }
    cout << res << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
}