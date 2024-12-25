#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    int div = n/k;
    if(div == 0){
        cout << 2 * n << endl;
    }
    else{
        int ans = div * n - k * (div) * (div - 1) / 2;
        ans += n % k;
        cout << ans * 2 << endl;
    }
}