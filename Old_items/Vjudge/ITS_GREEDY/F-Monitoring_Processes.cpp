#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tt, t = 1; scanf("%d", &tt);

	while (tt--)
	{
		int n; scanf("%d", &n);

		int a, b;
		map <int, int> lst;

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);

			lst[a]++;
			lst[b + 1]--;
		}

		auto it = lst.begin();
		auto it2 = it; it2++;
		for (; it2 != lst.end(); it++, it2++)
		{
			it2 -> second += it -> second;
		}

		int ans = 0;
		for (auto it = lst.begin(); it != lst.end(); it++)
			ans = max(ans, it -> second);

		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}