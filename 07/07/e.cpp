#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 1000'000'000'000'000'000;

signed main() {
    set<int> st;
    for(int k = 2; k <= 1000000; ++k) {
        int total = 1 + k + k * k;
        int cur = k * k;
        for(int m = 3; m <= 63; ++m) {
            if(cur > mx / k) break;
            cur *= k;
            total += cur;
            st.insert(total);
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(st.count(n)) {
            cout << "YES\n";
        } else {
            int k = ((int)sqrt(4 * n - 3) - 1) / 2;
            if(k > 1 && 1 + k + k * k == n) {
                cout << "YES\n"; 
            } else {
                cout << "NO\n";
            }
        }
    }
}