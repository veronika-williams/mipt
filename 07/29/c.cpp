#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<pair<int, int>> ans;
    int fl = 1;
    int fl2 = 1;
    for (auto &i : a)
    {
        if (i > 0)
            fl = 0;
        if (i < 0)
            fl2 = 0;
    }
    if (fl)
    {
        cout << n - 1 << endl;
        for (int i = n - 1; i >= 1; --i)
            cout << i << ' ' << i + 1 << endl;
    }
    else if (fl2)
    {
        cout << n - 1 << endl;
        for (int i = 1; i < n; ++i)
            cout << i + 1 << ' ' << i << endl;
    }
    else
    {
        int pos = 0, neg = 0;
        for (auto &i : a)
        {
            if (i >= 0)
                ++pos;
            else
                ++neg;
        }
        vector<pair<int, int>> ans;
        int i = -1, j = -1;
        for (int k = 0; k < n; ++k)
        {
            if (a[k] >= 0)
            {
                if (i == -1 || a[i] < a[k])
                    i = k;
            }
            else
            {
                if (j == -1 || a[j] > a[k])
                    j = k;
            }
        }
        if (abs(neg - pos) <= 4)
        {
            if (a[i] > -a[j])
            {
                // pos
                for (int k = 0; k < n; ++k)
                {
                    if (a[k] < 0)
                        ans.push_back({k, i});
                }
                cout << ans.size() + n - 1 << endl;
                for (auto &i : ans)
                    cout << i.first + 1 << ' ' << i.second + 1 << endl;
                for (int i = 1; i < n; ++i)
                    cout << i + 1 << ' ' << i << endl;
            }
            else
            {
                // neg
                for (int k = 0; k < n; ++k)
                {
                    if (a[k] > 0)
                        ans.push_back({k, j});
                }
                cout << ans.size() + n - 1 << endl;
                for (auto &i : ans)
                    cout << i.first + 1 << ' ' << i.second + 1 << endl;
                for (int i = n - 1; i >= 1; --i)
                    cout << i << ' ' << i + 1 << endl;
            }
        }
        else
        {
            if (neg > pos)
            {
                // neg
                while (a[j] >= -20)
                {
                    ans.push_back({j, j});
                    a[j] += a[j];
                }
                for (int k = 0; k < n; ++k)
                {
                    if (a[k] >= 0)
                    {
                        ans.push_back({k, j});
                    }
                }
                cout << ans.size() + n - 1 << endl;
                for (auto &i : ans)
                    cout << i.first + 1 << ' ' << i.second + 1 << endl;
                for (int i = n - 1; i >= 1; --i)
                    cout << i << ' ' << i + 1 << endl;
            }
            else
            {
                while (a[i] <= 20)
                {
                    ans.push_back({i, i});
                    a[i] += a[i];
                }
                for (int k = 0; k < n; ++k)
                {
                    if (a[k] < 0)
                    {
                        ans.push_back({k, i});
                    }
                }
                cout << ans.size() + n - 1 << endl;
                for (auto &i : ans)
                    cout << i.first + 1 << ' ' << i.second + 1 << endl;
                for (int i = 1; i < n; ++i)
                    cout << i + 1 << ' ' << i << endl;
            }
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}