#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,q;
int cookedsum = 0;
map<char, int> dict;
int arr[1005][1005];
bool cooked[1005][1005];
void cooking(int a, int b){
    if(arr[a+1][b] == 1){
        cookedsum++;
        cooked[a+1][b] = true;
        cooking(a+1,b);
    }
    if(arr[a-1][b] == 3){
        cookedsum++;
        cooked[a-1][b] = true;
        cooking(a-1,b);
    }
    if(arr[a][b+1] == 4){
        cookedsum++;
        cooked[a][b+1] = true;
        cooking(a,b+1);
    }
    if(arr[a][b-1] == 2){
        cookedsum++;
        cooked[a][b-1] = true;
        cooking(a,b-1);
    } 
}
void floodfill(int a, int b){
    set<pair<int,int>> vis;
    stack<pair<int,int>> dfs;
    dfs.push({a,b});
    pair<int,int> di[4] = {{1,0}, {-1, 0}, {0,-1}, {0,1}};
    int sum = 0;
    while(!dfs.empty()){
        int y,x;
        y = dfs.top().first;
        x = dfs.top().second;
        dfs.pop();
        if(a == 0 || b == 0 || a == n+1 || b == n+1){
            return;
        }
        for(int i = 0; i < 4; i++){
            int a1 = y + di[i].first;
            int b1 = x + di[i].second;
            if(cooked[a1][b1] == true){
                continue;
            }
            if(a1 == 0 || b1 == 0 || a1 == n+1 || b1 == n+1){
                return;
            }
            int s = vis.size();
            vis.insert({a1,b1});
            if(s != vis.size()){
                dfs.push({a1,b1});
            }
        }
    }
    cookedsum += vis.size();
    for(auto i : vis){
        cooked[i.first][i.second] = true;
    }
}
int32_t main (){
    dict['U'] = 1;
    dict['R'] = 2;
    dict['D'] = 3;
    dict['L'] = 4;
    cin >> n >> q;
    int sum = n*n;
    for(int i = 1; i <= q; i++){
        int x,y;
        char c;
        cin >> y >> x;
        cin >> c;
        if(cooked[y][x]){
            continue;
        }
        int dir = dict[c];
        arr[x][y] = dir;
        if(dir == 1){
            if(arr[y-1][x] == 3 || cooked[y-1][x] == true){
                cookedsum++;
                cooked[y][x] = true;
                if(cooked[y-1][x] == 3 && cooked[y-1][x] == false){
                    cookedsum++;
                    cooked[y-1][x] = true;
                    cooking(y-1,x);
                }
                cooking(y,x);
            }
        }
        if(dir == 2){
            if(arr[y][x+1] == 4 || cooked[y][x+1] == true){
                cookedsum++;
                cooked[y][x] = true;
                if(cooked[y][x+1] == 4 && cooked[y][x+1] == false){
                    cookedsum++;
                    cooked[y][x+1] = true;
                    cooking(y,x+1);
                }
                cooking(y,x);
            }
        }
        if(dir == 3){
            if(arr[y+1][x] == 1 || cooked[y+1][x] == true){
                cookedsum++;
                cooked[y][x] = true;
                if(cooked[y+1][x] == 1 && cooked[y+1][x] == false){
                    cookedsum++;
                    cooked[y+1][x] = true;
                    cooking(y+1,x);
                }
                cooking(y,x);
            }
        }
        if(dir == 4){
            if(arr[y][x-1] == 2 || cooked[y][x-1] == true){
                cookedsum++;
                cooked[y][x] = true;
                if(cooked[y][x-1] == 2 && cooked[y][x-1] == false){
                    cookedsum++;
                    cooked[y][x-1] = true;
                    cooking(y+1,x);
                }
                cooking(y,x);
            }
        }
        if(cooked[y+1][x] == false){
            floodfill(y+1, x);
        }
        if(cooked[y-1][x] == false){
            floodfill(y-1, x);
        }
        if(cooked[y][x+1] == false){
            floodfill(y, x+1);
        }
        if(cooked[y][x-1] == false){
            floodfill(y+1, x-1);
        }
        cout << cookedsum << endl;
    }
}