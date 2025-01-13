#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

stack<pii> monostack;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        while (!monostack.empty() && monostack.top().first >= n)
        {
            monostack.pop();
        }
        if (!monostack.empty())
        {
            cout << monostack.top().second << " ";
        }
        monostack.push({a, i});
    }
    return 0;
}