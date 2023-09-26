#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 1e16;
vector<vector<pair<int, int>>> g;
vector<int> used;
int fl = 0;

int dfs(int i) {
    if(fl) return 1;
    if(used[i] == mx) used[i] = 0;
    for(auto & [to, d] : g[i]) {
        if(used[to] == mx) {
            used[to] = used[i] + d;
            dfs(to);
        } else {
            if(used[to] != used[i] + d) {
                fl = 1;
                return 1;
            }
        }
    }
    return 0;
}

inline void solve() {
    fl = 0;
    int n, m;
    cin >> n >> m;
    used.assign(n, mx);
    g.assign(n, vector<pair<int, int>> ());
    for(int i = 0; i < m; ++i) {
        int v, u, d;
        cin >> v >> u >> d;
        --u, --v;
        g[v].push_back({u, d});
        g[u].push_back({v, -d});
    }
    for(int i = 0; i < n; ++i) {
        if(dfs(i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}