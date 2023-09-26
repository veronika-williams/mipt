#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> used, ord;

void dfs(int v) {
    if(used[v]) return;
    used[v] = 1;
    for(auto & to : g[v])  dfs(to);
    ord.push_back(v);
}

inline void solve() {
    ord.clear();
    int n, k;
    cin >> n >> k;
    vector<int> c(n), p(k);
    for(auto & i : c) cin >> i;
    for(auto& i : p) cin >> i;
    g.assign(n, vector<int> ());

    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for(int j = 0; j < m; ++j) {int x; cin >> x; g[i].push_back(x - 1);}
    }
    int res = 0;
    used.assign(n, 0);
    for(int i = 0; i < n; ++i) { if(!used[i]) dfs(i); }
    for(auto & i : p) c[i - 1] = 0;
    for(auto & x : ord) {
        if(g[x].empty()) continue;
        int cost = 0;
        for(auto & to : g[x]) cost += c[to];
        if(cost < c[x]) c[x] = cost;
    }
    for(auto & i : c) cout << i << ' ';
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}