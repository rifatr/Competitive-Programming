#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 5, inf = 1e9, M = 104;
int n, dp[N], k, a[M];

int f(int x)
{
	if (x < 0)
		return inf;
	if (x == 0)
		return 0;

	if (dp[x] != -1)
		return dp[x];

	int z = inf;
	for (int i = 0; i < k; i++)
		z = min(z, 1 + f(x - a[i]));

	return dp[x] = z;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> a[i];

	memset(dp, -1, sizeof dp);

	int ans = f(n);

	cout << (ans >= inf ? -1 : ans);
}