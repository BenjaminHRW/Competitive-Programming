#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
const int n = 6000000;
pii segtree[n];
int lazy[n];
pii children[n];
int unused = 2;

pii operation(pii a, pii b){
    return {max(a.first, a.first + b.first), a.second + b.second};
}

void pushdown(int p, int L, int R){
    if (children[p].first == 0){
        children[p].first = unused;
        unused++;
    }
    if(children[p].second == 0){
        children[p].second = unused;
        unused++;
    }
    int m = (L+R)/2;
    segtree[children[p].first] = {(m-L+1) * lazy[p], (m-L+1) * lazy[p]};
    segtree[children[p].second] = {(R-m) * lazy[p], (R-m) * lazy[p]};
    lazy[children[p].first] = lazy[p];
    lazy[children[p].second] = lazy[p];
    lazy[p] = 12345678910;
}

int query(int p, int L, int R, int h){
    if(L == R){
        return L - (segtree[p].first > h);
    }
    if(lazy[p] != 12345678910){
        pushdown(p,L,R);
    }
    int m = (L+R)/2;
    if( h < segtree[children[p].first].first){
        return query(children[p].first,L,m,h);
    }
    return query(children[p].second, m + 1, R, h - segtree[children[p].first].second);
}
void setrange(int p, int L, int R, int i, int j, int val){
    if(L != R && lazy[p] != 12345678910){
        pushdown(p, L, R);
    }
    if(i == L && j == R){
        lazy[p] = val;
        segtree[p] = {(R-L+1) * val, (R - L + 1) * val};
    }
    else{
        int m = (L + R) / 2;
        if(i <= m){
            if(children[p].first == 0){
                children[p].first = unused;
                unused++;
            }
            setrange(children[p].first, L, m,i,min(m,j), val);
        }
        if(j > m){
            if(children[p].second == 0){
                children[p].second = unused;
                unused++;
            }
            setrange(children[p].second, m+1, R, max(i,m+1), j, val);
        }
        segtree[p] = operation(segtree[children[p].first], segtree[children[p].second]);
    }
}
int32_t main(){
    int N;
    char c;
    cin >> N >> c;
    fill_n(lazy, min(2 * N, n), 12345678910);
    while(c != 'E'){
        if(c == 'I'){
            int a,b,D;
            cin >> a >> b >> D;
            setrange(1,1,N,a,b,D);
        }
        else{
            int h;
            cin >> h;
            cout << query(1,1,N,h) << endl;
        }
        cin >> c;
    }
}