#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int n, q, segtree[400001], instr, l, r, v;
pair<int, int> lazy[400001];
void pushdown(int cur)
{
    if (lazy[cur].first != 0)
    {
        lazy[cur * 2] = lazy[cur];
        lazy[cur * 2 + 1] = lazy[cur];
        segtree[cur * 2] = lazy[cur].first;
        segtree[cur * 2 + 1] = lazy[cur].first;
    }
    else
    {
        lazy[cur * 2].second += lazy[cur].second;
        lazy[cur * 2 + 1].second += lazy[cur].second;
    }
    segtree[cur * 2] += lazy[cur].second;
    segtree[cur * 2 + 1] += lazy[cur].second;
    lazy[cur] = {0, 0};
}
void pushup(int cur)
{
    segtree[cur] = min(segtree[cur * 2], segtree[cur * 2 + 1]);
}
void setupdate(int cur, int l, int r, int ul, int ur, int x)
{
    if (r < ul || l > ur)
        return;
    if (l == r)
    {
        segtree[cur] = x;
        return;
    }
    pushdown(cur);
    if (ul <= l && r <= ur)
    {
        segtree[cur] = x;
        lazy[cur] = {x, 0};
        return;
    }
    int m = (l + r) / 2;
    setupdate(cur * 2, l, m, ul, ur, x);
    setupdate(cur * 2 + 1, m + 1, r, ul, ur, x);
    pushup(cur);
}
void addupdate(int cur, int l, int r, int ul, int ur, int x)
{
    if (r < ul || l > ur)
        return;
    if (l == r)
    {
        segtree[cur] += x;
        return;
    }
    pushdown(cur);
    if (ul <= l && r <= ur)
    {
        segtree[cur] += x;
        lazy[cur].second += x;
        return;
    }
    int m = (l + r) / 2;
    addupdate(cur * 2, l, m, ul, ur, x);
    addupdate(cur * 2 + 1, m + 1, r, ul, ur, x);
    pushup(cur);
}
int query(int cur, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
        return 100000000000000;
    if (l == r)
        return segtree[cur];
    pushdown(cur);
    if (ql <= l && r <= qr)
    {
        return segtree[cur];
    }
    int m = (l + r) / 2;
    int leftres = query(cur * 2, l, m, ql, qr);
    int rightres = query(cur * 2 + 1, m + 1, r, ql, qr);
    return min(leftres, rightres);
}
int32_t main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        setupdate(1, 1, n, i, i, a);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> instr >> l >> r;
        if (instr != 3)
            cin >> v;
        if (instr == 1)
            addupdate(1, 1, n, l, r, v);
        if (instr == 2)
            setupdate(1, 1, n, l, r, v);
        if (instr == 3)
            cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}