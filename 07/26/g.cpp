#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> h, par, sz;
vector<vector<int>> g;

inline bool comp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    return get<2>(a) + h[get<0>(a)] < get<2>(b) + h[get<0>(b)];
}

inline bool comp2(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<0>(a) < get<0>(b);
}

inline int find(int a) {
    if(a == par[a]) return a;
    return par[a] = find(par[a]);
}

inline void unite(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a, b);
    par[a] = b;
    if(sz[a] == sz[b]) ++sz[b];
}

inline void solve() {
    h.clear(), par.clear(), sz.clear(), g.clear();
    int n, m;
    cin >> n >> m;
    h.assign(n, 0);
    for(auto & i : h) cin >> i;
    g.assign(n, vector<int> ());
    vector<tuple<int,int, int>> edges;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v), g[v].push_back(u);
        edges.push_back(make_tuple(max(h[v], h[u]), v, u));
    }
    sort(edges.begin(), edges.end(), comp2);
    int q;
    cin >> q;
    vector<tuple<int, int, int, int>> qu;
    for(int i = 0; i < q; ++i) {
        int a, b, e;
        cin >> a >> b >> e;
        --a, --b;
        qu.push_back(make_tuple(a, b, e, i));
    }
    sort(qu.begin(), qu.end(), comp);
    par.assign(n, 0); sz.assign(n, 0);
    for(int i = 0; i < n; ++i) par[i] = i;
    int run = 0;
    vector<int> ans(q, 0);
    for(auto i : qu) {
        int a = get<0>(i), b = get<1> (i), e = get<2> (i), ind = get<3>(i);
        while(run < m && get<0>(edges[run]) <= e + h[a]) {
            unite(get<1>(edges[run]), get<2>(edges[run]));
            ++run;
        }
        if(find(a) == find(b)) ans[ind] = 1;
    }
    for(auto & i : ans) cout << (i ? "YES\n" : "NO\n");
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}