#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int n) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return 0;
    }
    return 1;
}

inline void solve() {
    int n;
    cin >> n;
    vector<int> primes, a;
    for(int i = 1; i <= n; ++i) {
        if(check(i)) primes.push_back(i);
        else a.push_back(i);
    }
    vector<int> left, right;
    for(int i = 0; i < primes.size(); ++i) {
        if(i % 2 == 0) right.push_back(primes[i]);
        else left.push_back(primes[i]);
    }
    if(right.size() < left.size()) swap(left, right);
    reverse(left.begin(), left.end());
    for(auto& x : left) cout << x << ' ';
    for(int i = 1; i <= a.size() / 2; ++i) cout << a[i] << ' ';
    cout << 1 << ' ';
    for(int i = a.size() / 2 + 1; i < a.size(); ++i) cout << a[i] << ' ';
    for(auto& x : right) cout << x << ' '; 
    cout << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}