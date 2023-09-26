#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    for(int i = 1; i < 1000000; ++i) {
        if(n % i != 0) {
            cout << i - 1 << endl;
            return;
        }
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}