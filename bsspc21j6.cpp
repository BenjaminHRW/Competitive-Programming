#include <bits/stdc++.h>

using namespace std;


vector<int> edgelist[500005];
int weight[500005];
int cost[500005];
int dp[500005];
void dfs(int u, int p){
    vector<int> branches;
    cost[u] = weight[u];
    for(auto i : edgelist[u]){
        if(i != p){
            dfs(i, u);
            cost[u] += cost[i];
            dp[u] += cost[i];
            branches.push_back(dp[i] - cost[i]);
        }
    }
    sort(branches.begin(), branches.end());
    if(u == 1){
        for(int i = 0; i < min(3, (int)branches.size()); i++){
            dp[u] += branches[i];
        }
    }
    else{
        for(int i = 0; i < min(2, (int)branches.size()); i++){
            dp[u] += branches[i];
        }
    }
    
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> weight[i+2];
    }
    for(int i =0 ; i < n - 1; i++){
        int x,y;
        cin >> x >> y;
        edgelist[x].push_back(y);
        edgelist[y].push_back(x);
    }
    dfs(1,0);
    cout << dp[1] << endl;;
}