#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tt, t = 1; scanf("%d", &tt);

	while (tt--)
	{
		int n; scanf("%d", &n);

		int a[n], cnt[n] = {0};

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		string res = "yes";

		for (int i = 0; i < n; i++)
		{
			if (a[i] >= n)
			{
				res = "no";
				break;
			}

			cnt[a[i]]++;
		}

		for (int i = 0; i < n; ++i)
		{
			if (cnt[i] > 2)
			{
				res = "no";
				break;
			}

			if (cnt[i] == 2 and cnt[n - i - 1])
			{
				res = "no";
				break;
			}
		}


		printf("Case %d: ", t++);
		cout << res << '\n';
	}
	return 0;
}
