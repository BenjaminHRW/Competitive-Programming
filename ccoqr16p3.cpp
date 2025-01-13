#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
pair<int, int> triangle[100005];

int32_t main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < b; i++)
	{
		int x, y;
		cin >> x >> y;
		triangle[i] = {y, a - x + 1}; // x axis, y axis
	}
	sort(triangle, triangle + b);
	int totalsum = 0;
	pair<int, int> lastnum;
	lastnum = triangle[0];
	for (int i = 1; i < b; i++)
	{
		int diff = lastnum.second - (triangle[i].first - lastnum.first);
		long long z = 0;
		diff = max(diff, z);
		int area1 = lastnum.second * (lastnum.second + 1) / 2;
		int area2 = diff * (diff + 1) / 2;
		totalsum += area1 - area2;
		lastnum.second = max(lastnum.second - (triangle[i].first - lastnum.first), triangle[i].second);
		lastnum.first = triangle[i].first;
	}
	totalsum += lastnum.second * (lastnum.second + 1) / 2;
	cout << totalsum << endl;
}