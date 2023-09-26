#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<pair<int, int>>> g;

signed main() {
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<pair<int, int>>());
    for(int i = 0; i < m; ++i) {
        int u, v, y;
        cin >> u >> v >> y;
        --u, --v;
        g[u].push_back({v, y});
        g[v].push_back({u, y});
    }
    
}