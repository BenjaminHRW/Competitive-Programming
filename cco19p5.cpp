#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
set<int> vertices[100000];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        vertices[a].insert(b);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += vertices[i].size();
        int a = *vertices[i].begin();
        vertices[i].erase(a);
        if(vertices[a].size() <= vertices[i].size()){
            swap(vertices[a], vertices[i]);
        }
       vertices[a].insert(vertices[i].begin(), vertices[i].end());
    }
    cout << ans << endl;
}