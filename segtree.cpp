#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;

int segtree[400010];

void pushup(int cur) {
	segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1];
}

void update(int cur, int l, int r, int idx, int tar) {
	if (l == r) {
		segtree[cur] = tar;
		return;
	}
	int mid = l + (r - l) / 2;
	if (idx <= mid) {
		update(cur * 2, l, mid, idx, tar);
	}
	else {
		update(cur * 2 + 1, mid + 1, r, idx, tar);
	}
	pushup(cur);
}

int query(int cur, int l, int r, int ql, int qr) {
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return segtree[cur];
	}
	int m = (l + r) / 2;
	int leftRes = query(2 * cur, l, m, ql, qr);
	int rightRes = query(2 * cur + 1, m + 1, r, ql, qr);
	return leftRes + rightRes;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		update(1, 1, n, i, a);
	}
	for (int i = 0; i < m; i++) {
		char instr;
		int a, b;

		cin >> instr >> a >> b;
		if (instr == 'Q')
		{
			++a;
			++b;
			cout << query(1, 1, n, a, b) << endl;
		}
		else
		{
			++a;
			update(1, 1, n, a, b);
		}
	}

}