#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 30;

int main()
{
	int tt, t = 1; scanf("%d", &tt);

	while (tt--)
	{
		int n; scanf("%d", &n);

		int a[n + 1]; a[0] = 0;

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i + 1]);

		int ans = inf, l = 0, h = a[n] + 10, m;

		while (h - l > 1)
		{
			m = l + ((h - l) / 2);

			int c = m;
			for (int i = 0; i < n; i++)
			{
				int p = a[i + 1] - a[i];

				if (p > c)
				{
					c = -1;
					break;
				}

				if (p == c) c--;
			}

			if (c < 0)
				l = m;
			else
				h = m, ans = min(ans, m);
		}


		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}