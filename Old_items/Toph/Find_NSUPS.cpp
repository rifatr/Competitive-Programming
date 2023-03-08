#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, n) for(int i = a; i < n; i++)


const int N = 1e3+3;
string wanted = "NSUPS", given;
ll dp[N][5], n;

ll f(int p, int x)
{
	if(p >= 5 and x <= n)
		return 1;

	if(x >= n)
		return 0;

	if(dp[x][p] != -1)
		return dp[x][p];

	ll cnt = 0;

	lop(x, n)
	{
		if(given[i] == wanted[p])
			cnt += f(p + 1, i + 1);
	}

	return dp[x][p] = cnt;
}

int main()
{
	cin >> n >> given;

	memset(dp, -1, sizeof dp);

	cout << f(0, 0) << '\n';
}
