#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int colsum[n + 1][n + 1], m, ans = -INT_MAX;
	memset(colsum, 0, sizeof colsum);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; j++)
		{
			cin >> m;
			colsum[i][j] = colsum[i - 1][j] + m;
		}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = i; k <= n; k++)
			{
				int sum = 0;
				for (int kk = j; kk <= n; kk++)
				{
					sum += colsum[k][kk] - colsum[i - 1][kk];
					ans = max(ans, sum);
					sum = max(0, sum);
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}