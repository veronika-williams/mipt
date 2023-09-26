#include <bits/stdc++.h>
using namespace std;
#define int long long 

inline int check(vector<string> v, char c) {
    for(int i = 0; i < 3; ++i) {
        if(v[i][0] == v[i][1] && v[i][0] == v[i][2] && v[i][0] == c) return 1;
        if(v[0][i] == v[1][i] && v[0][i] == v[2][i] && v[0][i] == c) return 1;
    }
    if(v[0][0] == v[1][1] && v[0][0] == v[2][2] && v[0][0] == c) return 1;
    if(v[0][2] == v[1][1] && v[2][0] == v[0][2] && v[0][2] == c) return 1;
    return 0;
}

inline void solve() {
    vector<string> v(3);
    for(auto & i : v) cin >> i;
    if(check(v, '+')) {
        cout << "+\n";
        return;
    }
    if(check(v, 'X')) {
        cout << "X\n";
        return;
    }
    if(check(v, 'O')) {
        cout << "O\n";
        return;
    }
    cout << "DRAW\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}