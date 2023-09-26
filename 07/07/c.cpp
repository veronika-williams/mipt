#include <bits/stdc++.h>
using namespace std;
#define int long long

inline bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first > b.first) return 1;
    if(a.first < b.first) return 0;
    if(a.second < b.second) return 1;
    return 0;
}

inline void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> a(n, vector<int> (m));
    for(auto & i : a) for(auto & j : i) cin >> j;
    for(int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    vector<pair<int, int>> ans;
    pair<int, int> x;
    for(int i = 0; i < n; ++i) {
        int cur = 0, cnt = 0;
        int total = 0;
        for(int j = 0; j < m; ++j) {
            if(cur + a[i][j] <= h) {
                ++cnt, cur += a[i][j];
                total += cur;
            } else break;
        }
        ans.push_back({cnt, total});
        if(i == 0) x = {cnt, total};
    }
    sort(ans.begin(), ans.end(), comp);
    for(int i = 0; i < n; ++i) {
        if(ans[i] == x) {
            cout << i + 1 << endl;
            return;
        }
    }
    
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}