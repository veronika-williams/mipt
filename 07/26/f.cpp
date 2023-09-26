#include <bits/stdc++.h>
using namespace std;
#define int long long

int k;
int mxlen = 0, mx = 0;
vector<pair<int, int>> res;

struct node {
    node * left = nullptr, * right = nullptr;
    int cnt = 0;
    vector<int> v;
};

node * add(node * root, int x, int ind) {
    node * run = root;
    ++run->cnt;
    run->v.push_back(ind);
    for(int i = k - 1; i >= 0; --i) {
        int r = (x >> i) & 1;
        if(!run->left) run->left = new node();
        if(!run->right) run->right = new node();
        if(r == 0) run = run->left;
        else run = run->right;
        ++run->cnt;
        run->v.push_back(ind);
    }
    return root;
}

void dfs(node * root, int cnt, int cur) {
    if(!root || root->cnt < 2) return;
    int fl = 1;
    if(root->left && root->left->cnt > 1) fl = 0, dfs(root->left, cnt + 1, cur << 1);
    if(root->right && root->right->cnt > 1) fl = 0, dfs(root->right, cnt + 1, (cur << 1) + 1);
    if(fl && cnt > mxlen) {mxlen = cnt, mx = cur; res.clear();}
    if(fl && cnt == mxlen) {res.push_back({root->v[0], root->v[1]}); }
}

inline void solve() {
    res.clear();
    mxlen = 0, mx = 0;
    int n;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    node * root = new node();
    for(int i = 0; i < n; ++i) root = add(root, a[i], i);
    dfs(root, 0, 0);
    int I = 0, J = 1, ans = 0;
    for(auto[i, j] : res) {
        int cur_ans = 0;
        for(int c = 0; c < k; ++c) {
            if(((a[i] >> c) & 1) == ((a[j] >> c) & 1)) cur_ans += (1 << c);
        }
        if(cur_ans > ans) I = i, J = j, ans = cur_ans;
    }
    int x = 0;
    for(int i = 0; i < k; ++i) {
        if(!((a[I] >> i) & 1)) x += (1 << i);
    }
    cout << I + 1 << ' ' << J + 1 << ' ' << x << endl;
    delete root;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}
