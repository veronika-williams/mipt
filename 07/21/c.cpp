#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    string s;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            char c;
            cin >> c;
            if(c != '.') s += c;
        }
    }
    cout << s << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}