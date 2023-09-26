#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

inline int get2(vector<int> v, int t) {
    int sum = (t / 4) * 20;
    t %= 4;
    for(int i = 0; i < t; ++i) sum += v[i];
    return sum;
}

inline int get(int x, int t) {
    if(t == 0) return 0;
    if(t == 1 || x == 5 || x == 0) return x;
    int sm = 0;
    if(x == 1 || x == 6) {
        sm = x + get2({2, 4, 8, 6}, t - 1);
    } else if (x == 7 || x == 2) {
        sm = x + get2({4, 8, 6, 2}, t - 1);
    } else if(x == 9 || x == 4) {
        sm = x + get2({8, 6, 2, 4}, t - 1);
    } else {
        sm = x + get2({6, 2, 4, 8}, t - 1);
    }
    return sm;
}

inline int f(int s, int n, int x) {
    s += get(s % 10, x);
    return s * (n - x);
}

inline void solve() {
    int s, n;
    cin >> s >> n;
    int l = 0, r = n - 1;
    while(l + 3 <= r) {
        int l1 = (2 * l + r) / 3;
        int r1 = (2 * r + l) / 3;
        if(f(s, n, l1) < f(s, n, r1)) {
            l = l1;
        } else r = r1;
    }
    int res = max(f(s,n, l), f(s, n, r));
    if(l + 1 < n) res = max(res, f(s, n, l+ 1));
    cout << res << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}