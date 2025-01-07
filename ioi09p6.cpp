#include <bits/stdc++.h>

using namespace std;

#define int long long

int bees[810][810];
namespace
{
    std::pair<int,int> operator+(const std::pair<int,int> &a ,const  std::pair<int,int> &b )
    {
        return std::make_pair(a.first+b.first,a.second+b.second);
    }
}
pair<int,int> p[4] = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
pair<int,int> start;
pair<int,int> en;
int n,s;
int vis[810][810];
bool works(int honey){
    stack<pair<int,int>> dfs;
    dfs.push({start});
    for(int i = 0; i < 810; i++){
         for(int j = 0; j < 810; j++){
            vis[i][j] = INT_MAX;
         }
    }
    vis[start.first][start.second] = honey;
    while(!dfs.empty()){
        int num = vis[dfs.top().first][dfs.top().second];
        pair<int,int> loc = dfs.top();
        dfs.pop();
        for(int a = 0; a < 4; a++){
            pair<int,int> temp = loc + p[a];
            int i = temp.first;
            int j = temp.second;
            if(bees[i][j] != -1 && bees[i][j] != 0 && bees[i][j] > num && vis[i][j] > num + 1){
                dfs.push(temp);
                vis[i][j] = num + 1;
            }
        }  
    }   
    if(vis[en.first][en.second] != INT_MAX){
        return true;
    }
    return false;
}
int32_t main(){
    unordered_map<char,int> dict = {{'T', -1}, {'G', INT_MAX}, {'M', INT_MAX}, {'D', INT_MAX}, {'H', 0}};
    cin >> n >> s;
    queue<pair<pair<int,int>,int>> bfs;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            bees[i][j] = dict[c];
            if(c == 'M'){
                start = {i,j};
            }
            if(c == 'D'){
                en = {i,j};
            }
            if(c == 'H'){
                bfs.push({{i,j}, 0});
            }
        }
    }
    while(!bfs.empty()){
        int num = bfs.front().second;
        for(int a = 0; a < 4; a++){
            pair<int,int> temp = bfs.front().first;
            temp = temp + p[a];
            int i = temp.first;
            int j = temp.second;
            if(bees[i][j] != -1 && !(i == en.first && j == en.second)  && bees[i][j] > num + s){
                bees[i][j] = num + s;
                bfs.push({temp, num+s});
            }
        }  
        bfs.pop();
    }  
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << bees[i][j] << " ";
        }
        cout << endl;
    }*/
    int l = 1; 
    int r = bees[en.first][en.second];
    bool test = works(3);
    if(works(0) == false){
        cout << -1 << endl;
        return 0;
    }
    else{
        while(l < r){
            int mid = l + (r - l) / 2;
            if(works(mid) == true){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        if(works(l)){
            cout << l / s << endl;
        }
        else{
            cout << (l -1)/s << endl;
        }
    }
}