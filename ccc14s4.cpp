#include<bits/stdc++.h>

using namespace std;

int n,k;
#define int long long

map<int,int> Xi, Yi, iX, iY;

int X1[1010],Y1[1010],X2[1010],Y2[1010],T[1010];
int tint[2020][2020];
int32_t main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    set<int> Xs,Ys;
    for (int i = 0; i < n; i++){
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i] >> T[i];
        Xs.insert(X1[i]);
        Xs.insert(X2[i]);
        Ys.insert(Y1[i]);
        Ys.insert(Y2[i]);
    }
    int xcount = 1,ycount = 1;
    for (int i : Xs)
    {
        iX[xcount] = i;
        Xi[i] = xcount++;
    }
    for (int i : Ys)
    {
        iY[ycount] = i;
        Yi[i] = ycount++;
    }
    for (int i = 0; i < n; i++){
        for (int j = Yi[Y1[i]]; j < Yi[Y2[i]]; j++)
        {
            tint[j][Xi[X1[i]]] += T[i];
            tint[j][Xi[X2[i]]] -= T[i];
        }
    }
    for (int i = 1;i < ycount; i++){
        for(int j = 1; j < xcount; j++)
        {
            tint[i][j]+=tint[i][j-1];
        }
    }
    int tot = 0;
    for (int i = 1;i < ycount; i++){
        for (int j = 1;j < xcount; j++){
            if (tint[i][j] >= k)
            {
                tot += (iY[i+1]-iY[i])*(iX[j+1]-iX[j]);
            }
        }
    }
    cout << tot << endl;
    return 0;
}