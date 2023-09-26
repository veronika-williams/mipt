#include<bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int, int>> a(m);
    for(auto & i : a) {
        cin >> i.first >> i.second;
        --i.first, --i.second;
    }
    vector<int> suf(n, 0), pref(n, 0);

    int pos = -1;
    for(int i = 0; i < n; ++i)  {
        if(s[i] == '0') pos = i;
        pref[i] = pos;
    }
    pos = n;
    for(int i = n - 1; i >= 0; --i) {
        if(s[i] == '1') pos = i;
        suf[i] = pos;
    }

    int init = 0;
    set<pair<int, int>> st;
    for(auto& i : a) {
        i.first = suf[i.first];
        i.second = pref[i.second];
        if(i.first >= i.second) init = 1;
        else st.insert(i);
    }
    cout << st.size() + init << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}