#include <bits/stdc++.h>

using namespace std;

int on[10005];
int off[10005];
bool pos[9];
int main(){
    int n,c;
    cin >> n >> c;
    int x;
    int q = 0;
    cin >> x;
    while(x != -1){
        on[q] = x;
        cin >> x;
        q++;
    }
    q = 0;
    cin >> x;
    while(x != -1){
        off[q] = x;
        cin >> x;
        q++;
    }
    
}