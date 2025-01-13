#include <bits/stdc++.h>

using namespace std;

#define int long long

double val[1000005];
pair<double, int> sor[1000005];
int32_t main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> val[i];
        if(val[i] < 0){
            sor[i] = {val[i] * -1 / 2, 2};
        }
        else{
            sor[i] = {val[i], 1};
        }
    }
    sort(sor, sor + n, std::greater<>());
    int ma = 0; 
    int pos = 0;
    n--;
    while(k > 2 && pos < n){
        if(sor[pos].second == 2){
            ma += sor[pos].first * 2;
            k -= 2;
        }
        else{
            ma += sor[pos].first;
            k -= 1;
        }
        pos++;
    }
    int counter = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    bool m = false;
    while(counter != 2){
        if(sor[pos].second == 2 && m == false ){
            num1 = sor[pos].first * 2;
            m = true;
        }
        if(sor[pos].second != 2){
            num2 += sor[pos].first;
            num3 = sor[pos].first;
            counter++;
        }
        pos++;
    }  
    if(k == 2){
        ma += max(num1, num2);
    }
    else{
        ma += num2- num3;
    }
    cout << ma << endl;
    
}