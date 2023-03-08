#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);

	for (int z = 1; z <= t; z++)
	{
		int n, w;
		scanf("%d %d", &n, &w);

		int x, y[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &x, &y[i]);
		}

		sort(y, y + n);

		int mv = 1, p = y[0] + w;

		for (int i = 0; i < n; ++i)
		{
			if (y[i] > p)
			{
				p = y[i] + w;
				mv++;
			}
		}

		printf("Case %d: %d\n", z, mv);
	}
	return 0;
}