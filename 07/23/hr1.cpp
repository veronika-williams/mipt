#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;
 
inline int Power(int a, int n) {
    int res = 1;
    while(n) {
        if(n & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

int solve(int n, int m) {
    --m;
    int up = 1;
    for (int i = n + 1; i <= n + m; ++i) up *= i, up %= mod;
    int down = 1;
    for(int i = 1; i <= m; ++i) down *= i;
    down = Power(down, mod - 2);
    return up * down % mod;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
}