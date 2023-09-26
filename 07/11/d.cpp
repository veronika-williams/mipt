#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n;
    cin >> n;
    int mn = n + 1;
    // найти наименьшее число не являющееся делителем
    for (int i = 2; i < n; ++i) {
        if(n % i != 0) {
            mn = i;
            break;
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << (char) ('a' + i % mn);
    }
    cout << "\n";

}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}