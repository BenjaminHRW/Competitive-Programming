#include <bits/stdc++.h>

using namespace std;

pair<int,int> zombies[2001];
int ysum [4001];
int n,m,k,q;
long long area(int Q){
    memset(ysum, 0, sizeof(ysum));
    vector<tuple<int,int,int,int>> edges;
    map<int,int> mapping;
    vector<long long> points;
    for(int i = 0; i < k; i++){
        int x = max(0,zombies[i].first - Q - 1);
        int y1 = max(0, zombies[i].second - Q - 1);
        int y2 = min(m, zombies[i].second + Q);
        mapping[y1] = -1;
        mapping[y2] = -1;
        edges.push_back({x,y1,y2,1});
        x = min(n, zombies[i].first + Q);
        edges.push_back({x,y1,y2,-1});
    }
    sort(edges.begin(), edges.end());
    int t = 0;
    for(auto x : mapping){
        points.push_back(x.first);
        mapping[x.first] = t;
        t++;
    }
    long long output = 0;
    for(int i = 0; i < edges.size(); i++){
        for(int j = mapping[get<1>(edges[i])]; j < mapping[get<2>(edges[i])]; j++){
            ysum[j] += get<3>(edges[i]);
        }
        for(int j = 0; j < points.size(); j++){
            if(ysum[j] > 0){
                output += (points[j+1] - points[j]) * (get<0>(edges[i+1]) -get<0>(edges[i]));
            }
        }
    }
    return output;
}
int main(){
    cin >> n >> m;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> zombies[i].first >> zombies[i].second;    
    }
    cin >> q;
    if(q == 0){
        cout << k << endl;
    }
    else if(q == 1){
        cout << area(q) - k << endl;
    }
    else{
        cout << area(q) - area(q-1) << endl;
    }
}