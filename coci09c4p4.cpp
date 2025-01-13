#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define endl '\n'

using namespace std;

int arr[1000005];
deque<pii> monodeque;
int swoops = 0;
int best[1000005];
void push(int val)
{
    int count = 0;
    while (!monodeque.empty() && monodeque.back().first >= val)
    {
        count += monodeque.back().second + 1;
        monodeque.pop_back();
    }
    monodeque.push_back({val, count});
}
void pop()
{
    if (monodeque.front().second > 0)
    {
        monodeque.front().second--;
        return;
    }
    monodeque.pop_front();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < x - 1; i++)
    {
        push(arr[i]);
    }
    for (int i = x - 1; i < n; i++)
    {
        push(arr[i]);
        best[i - x + 1] = monodeque.front().first;
        pop();
    }
    monodeque.clear();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (best[i] != 0)
        {
            if (monodeque.size() == 0 || best[i] > monodeque.front().first)
            {
                swoops++;
                monodeque.clear();
                monodeque.push_back({best[i], i + x - 1});
            }
            else if (monodeque.back().first == best[i] && best[i + 1] < best[i])
            {
                swoops++;
                monodeque.clear();
                monodeque.push_back({best[i], i + x - 1});
            }
            else if (monodeque.back().first != best[i] && best[i] != best[i + 1])
            {
                swoops++;
                monodeque.push_back({best[i], i + x - 1});
            }
        }
        sum += arr[i] - monodeque.front().first;
        if (monodeque.front().second == i)
        {
            monodeque.pop_front();
        }
    }
    cout << sum << endl
         << swoops << endl;
}