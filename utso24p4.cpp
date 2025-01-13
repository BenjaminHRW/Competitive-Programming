#include <bits/stdc++.h>

using namespace std;

#define int long long
int32_t main(){
    int n;
    int counter = 0;
    cin >> n;
    int sum = 1;
    double m = 2;
    while(n > 0 && sum < pow(10,10)){
        if(sum * m > pow(10,10)){
            m = 0.5;
        }
        if(sum == 1){
            m = 2;
        }
        if(n == 1){
            cout << sum;
            counter++;
        }
        else{
            cout << sum << " ";
            counter++;
        }
        sum *= m;
        n--;
    }
    cout << endl;
}