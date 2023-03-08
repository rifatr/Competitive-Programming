#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 5, inf = 1e9, M = 104;
int n, dp[N];

int f(int x)
{
	if (x == 0)
		return 0;

	if (dp[x] != -1)
		return dp[x];

	dp[x] = inf;
	int y = x;
	while (y)
	{
		int z = y % 10;
		dp[x] = min(dp[x], 1 + f(x - z));
		y /= 10;
	}
	return dp[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	memset(dp, -1, sizeof dp);

	cout << f(n) << '\n';
}