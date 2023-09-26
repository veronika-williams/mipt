#include<bits/stdc++.h>
using namespace std;
#define int long long

inline bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i) {
        v.push_back({(a[i] - 1) % k + 1, i + 1});
    }
    sort(v.begin(), v.end(), comp);
    for(auto & i : v) cout << i.second << ' ';
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}