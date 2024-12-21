#include<bits/stdc++.h>

using namespace std;

int n,k;
#define int long long

int arr[100005];
bool marked[100005];
int segtree[400010];

void pushup(int cur) {
	segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1];
}

void update(int cur, int l, int r, int idx, int tar) {
	if (l == r) {
		segtree[cur] += tar;
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
int32_t main(){
    int t;
    cin >> t;
    for(int testcase = 0; testcase < t; testcase++){
        int ans = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        arr[n] = INT_MAX;
        sort(arr, arr + n);
        vector<tuple<int,int,int>> restr;
        for(int i = 0; i < k; i++){
            int a,b,c;
            a++; b++;
            cin >> a >> b >> c;
            restr.push_back({b,a,c});
        }
        sort(restr.begin(), restr.end());
        for (auto d : restr){
            int b = get<0>(d);
            int a = get<1>(d);
            int c = get<2>(d);
            int l = lower_bound(arr, arr+n, a) -arr;
            int r = upper_bound(arr, arr + n, b) - arr - 1;
            int needed = c - query(1, 1, n, l, r);
            int counter = 0;
            while(needed > 0){
                if(marked[r- counter ] == false){
                    marked[r- counter ] = true;
                    int val = arr[r-counter];
                    update(1,1,n,r - counter, 1);
                    needed--;
                    ans++;
                }
                counter++;
            }
        }
        memset(arr, 0, 100004);
        memset(marked, false, 100004);
        memset(segtree, 0, 400010);
        cout << n - ans << endl;
    }
}