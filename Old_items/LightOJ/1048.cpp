#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1 << 30;

int main()
{
	int t; cin >> t;

	for (int z = 1; z <= t; z++)
	{
		ll n, k;
		cin >> n >> k;
		k++;

		ll a[n + 1], l = 0, h = 100, m, ans = inf * 100;
		for (int i = 0; i <= n; i++)
			cin >> a[i], h += a[i];

		while (h - l > 1)
		{
			m = (l + h) / 2;
			ll c = 1, s = 0;

			for (int i = 0; i <= n; i++)
			{
				if (a[i] > m)
				{
					c = inf;
					break;
				}

				if (s + a[i] > m)
					s = 0, c++;
				s += a[i];
			}

			if (c <= k) h = m;
			else l = m;
			if (c <= k) ans = min(ans, m);
		}

		cout << "Case " << z << ": " << ans << '\n';
		ll s, com = n + 1 - k;
		for (int i = 0; i <= n; i++)
		{
			if (!com)
				cout << a[i] << '\n';
			else
			{
				s = a[i];
				for (int j = i + 1; j <= n and com; j++, com--)
				{
					if (s + a[j] > ans) break;

					s += a[j];
					i++;
				}
				cout << s << '\n';
			}
		}

	}

	return 0;
}
