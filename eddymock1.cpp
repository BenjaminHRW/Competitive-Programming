#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

vector<tuple<int, int, int, int>> regions;
bool yes[100000];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, n;
    cin >> r >> n;
    for (int i = 0; i < r; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        tuple<int, int, int, int> temp = {a, b, a + c, b + d};
        regions.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < r; j++)
        {
            if (x >= get<0>(regions[j]) && x < get<2>(regions[j]) && y >= get<1>(regions[j]) && y < get<3>(regions[j]))
            {
                yes[j] = true;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < r; i++)
    {
        if (yes[i])
        {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}