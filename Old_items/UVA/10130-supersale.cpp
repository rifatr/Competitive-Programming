#include <bits/stdc++.h>

using namespace std;

const int N = 1004, inf = 1 << 28;
int n, g, price[N], weight[N], dp[N][32];

int f(int i, int w)
{
	if (w < 0)
		return -inf;
	if (i == n)
		return 0;

	int &x = dp[i][w];
	if (x != -1)
		return x;

	return x = max(f(i + 1, w), price[i] + f(i + 1, w - weight[i]));
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		memset(dp, -1, sizeof dp);

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> price[i] >> weight[i];

		cin >> g;
		int ans = 0;
		for (int i = 0; i < g; i++)
		{
			int mw;
			cin >> mw;

			ans += max(0, f(0, mw));
		}

		cout << ans << '\n';
	}

	return 0;
}