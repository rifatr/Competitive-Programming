#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7, N = 1e6 + 5, inf = 1e17;
ll n, dp[N];

ll f(ll x)
{
	if (x < 0)
		return 0;
	if (x == 0)
		return 1;

	if (dp[x] != -1)
		return dp[x];

	dp[x] = 0;
	for (int i = 1; i <= 6; i++)
		dp[x] = (dp[x] + f(x - i)) % mod;

	return dp[x];
}

int main()
{
	cin >> n;

	memset(dp, -1, sizeof dp);

	cout << f(n);
}