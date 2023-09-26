#include<bits/stdc++.h>
using namespace std;
#define int long long

const int k = 10000; // количество итераций алгоритма
int n = 20;

int f(vector<int> p) {
    int s = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(p[i] <= p[j]) ++s;
        }
    }
    return s;
}

vector<int> g(const vector<pair<int, int>> & v, const vector<int> &a) {
    vector<int> b = a;
    for(auto & i : v) {
        b[i.first] += b[i.second];
    }
    return b;
}

inline int check(const vector<int>&a) {
    for(int i = 0; i < n - 1; ++i) {
        if(a[i] > a[i + 1]) return 0;
    }
    return 1;
}

// генерирует действительное число от 0 до 1
double rnd() { return double(rand()) / RAND_MAX; }

inline int solve() {
    vector<int> a(n);
    for(auto & i : a) i = rand() % 41 - 20;
    vector<pair<int, int>> v(50);
    for(auto& i : v) {
        i.first = rand() % n, i.second = rand() % n;
    }
    int ans = f(g(v, a)); // текущий лучший ответ
    double t = 1;
    for (int i = 0; i < k && ans != n * (n - 1) / 1; i++) {
        t *= 0.99;
        vector<pair<int, int> > u = v;

        
        int c = rand() % 50;
        u[c].first = rand() % n;
        u[c].second = rand() % n;

        for(auto & [x, y] : u) {
            if(x < y && a[y] > 0 && a[x] > 0) swap(x, y);
            if(x > y && a[y] < 0 && a[x] < 0) swap(x, y); 
        }


        int val = f(g(u, a));
        if (val > ans || rnd() < exp((val - ans) / t)) {
            v = u;
            ans = val;
        }
    }
    // for(auto & i : g(v, a)) cout << i << ' ' ;
    // cout << endl;

    // cout << v.size() << endl;
    // for(auto& i : v) cout << i.first + 1 << ' ' << i.second + 1 << endl;

    if(ans == n * (n - 1) / 2) cout << "YES\n";
    else {
        for(auto & i : a) cout << i << ' ' ;
        cout << endl;
        for(auto & i : g(v, a)) cout << i << ' ' ;
        cout << endl;
        return 0;
    }
    return 1;
}

signed main() {
    int t = 1000;
    while(t--) {
        if(!solve()) {
            cout << "FUCK" << endl;
            return 0;
        }
        if(t % 10 == 0) cout << t << endl; 
    }
    cout << "OK" << endl;
}