#include<bits/stdc++.h>

using namespace std;

int n,k;
#define int long long


int arr[500005];
int32_t main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int s;
        cin >> s;
        int sum = 0;
        for(int j =1 ; j <= s ; j++){
            cin >> arr[j];
            sum += arr[j];
        }
        int maxsum = 0;
        int asum = 0;
        for(int j = 1; j <= s/2 - 1;j++){
            asum += arr[j];
        }
        maxsum = max(asum, maxsum);
        int counter = s;
        for(int j = s/2-1; j > 0; j--){
            asum -= arr[j];
            asum += arr[counter];
            counter--;
            maxsum = max(asum, maxsum);
        }
        cout << sum - maxsum << " " << maxsum << endl;
        memset(arr, 0, 500005);
    }
}
