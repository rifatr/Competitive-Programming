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

		ll a[n], l = 0, h = 100, m, ans = inf * 100;
		for (int i = 0; i < n; i++)
			cin >> a[i], h += a[i];

		while (h - l > 1)
		{
			m = (l + h) / 2;
			ll c = 1, s = 0;

			for (int i = 0; i < n; i++)
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

			//cout << m << ' ' << c << '\n';

			if (c <= k)
				h = m, ans = min(ans, m);
			else
				l = m;
		}

		cout << "Case " << z << ": " << ans << '\n';
	}

	return 0;
}