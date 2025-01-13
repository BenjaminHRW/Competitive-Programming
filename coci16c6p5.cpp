#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define pii pair<int,int>

set<int> cards;
int parent[100005];
int height[100005];
void make(int n)
{
    parent[n] = n;
}
int find(int n)
{
    if (parent[n] == n)
        return n;
    parent[n] = find(parent[n]);
    return parent[n];
}
void join(int a, int b)
{
    if (find(a) == find(b))
        return;
    int x = find(a);
    int y = find(b);
    if (height[x] > height[y])
        swap(x, y);
    parent[x] = y;
    if (height[x] == height[y])
        ++height[y];
}
int32_t main(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> edgelist;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cards.insert(x);
    }
    if(*cards.begin() == 1){
        cout << 0 << endl;
        return 0;
    }
    int largest = *prev(cards.end());
    for(int x : cards){
        if(x == largest){
            break;
        }
        int value = *cards.lower_bound(x+1);
        int index = distance(cards.begin(), cards.find(x));
        if(value - x < x){
            edgelist.push_back({value % x, index, distance(cards.begin(), cards.find(value))});
        }
        for(int i = 2*x; i <= largest; i+= x){
            if(value - i < x){
            edgelist.push_back({value % x, index, distance(cards.begin(), cards.find(value))});
            }
        }
    }
    for(int i = 0; i < 100005; i++){
        parent[i] = i;
        height[i] = 1;
    }
    sort(edgelist.begin(), edgelist.end());
    int total = 0;
    for(auto x : edgelist){
        if(find(get<1>(x)) != find(get<2>(x))){
            join(get<1>(x), get<2>(x));
            total += get<0>(x);
        }
    }
    cout << total << endl;
}