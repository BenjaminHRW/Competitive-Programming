#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

bool recur(string a, string b)
{
    if (a == b)
    {
        return true;
    }
    if (a.length() < b.length())
    {
        return false;
    }
    for (int i = 0; i < a.length() - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            string newstring = a.substr(0, i);
            newstring.push_back(a[i] + 1);
            newstring = newstring + a.substr(i + 2);
            if (recur(newstring, b))
            {
                return true;
            }
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        bool tru = recur(a, b);
        if (tru)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}