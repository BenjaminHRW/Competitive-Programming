#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

bool grid[100][100];
int level, width, xcoord;

void print()
{
    for (int i = 0; i <= width; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (grid[i][j])
            {
                cout << 1 << " ";
            }
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
bool isedge(int x, int y)
{
    return grid[x][y] || grid[x][y + 1] || grid[x + 1][y] || grid[x + 1][y + 1] & !(grid[x][y] && grid[x][y + 1] && grid[x + 1][y] && grid[x + 1][y + 1]);
}

void fil(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            grid[i][j] = true;
        }
    }
}
// 1 up -1 down 1 right -1 left
void simulate(int dir, bool hor, int l, int r, int other, int lev)
{
    if (lev == level)
    {
        return;
    }
    lev++;
    if (hor)
    {
        int y1 = other;
        int y2 = other + ((r - l) / 3) * dir;
        pii coord1 = {l + (r - l) / 3, y1};
        pii coord2 = {l + (r - l) / 3 * 2, y2};
        fil(coord1.first, coord1.second, coord2.first, coord2.second);
        simulate(dir, true, coord1.first, coord2.first, coord2.second, lev);
        simulate(dir, true, l, coord1.first, coord1.second, lev);
        simulate(dir, true, coord2.first, r, coord1.second, lev);
        simulate(1, false, min(y1, y2), max(y1, y2), coord2.first, lev);
        simulate(-1, false, min(y1, y2), max(y1, y2), coord1.first, lev);
    }
    else
    {
        pii coord1 = {l + (r - l) / 3, other};
        pii coord2 = {l + (r - l) / 3 * 2, other + ((r - l) / 3) * dir};
        swap(coord1.first, coord1.second);
        swap(coord2.first, coord2.second);
        fil(coord1.first, coord1.second, coord2.first, coord2.second);
        simulate(dir, false, coord1.first, coord2.first, coord2.second, lev);
        simulate(dir, false, l, coord1.first, coord1.second, lev);
        simulate(dir, false, coord2.first, r, coord1.second, lev);
        simulate(1, true, min(coord1.first, coord2.first), max(coord1.first, coord2.first), coord2.second, level);
        simulate(-1, true, min(coord1.first, coord2.first), max(coord1.first, coord2.first), coord1.second, level);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> level >> width >> xcoord;
    simulate(1, true, 0, width, 1, 0);
    int count = 0;
    for (int i = 0; i <= 90; i++)
    {
        if (isedge(xcoord, i))
        {
            cout << i << " ";
        }
    }
    print();
    return 0;
}