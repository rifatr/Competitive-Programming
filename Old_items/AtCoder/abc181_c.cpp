#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ll n, a, b;

	cin >> n;
	pair <ll, ll> c[n + 1];

	for (int i = 0; i < n; i++)
	{
		cin >> c[i].first >> c[i].second;
	}

	ll f = 0;

	for (int i = 0; i < n and !f; i++)
	{
		int p = 1, q = 1;
		for (int j = i + 1; j < n and !f; j++)
		{
			if (c[j].first == c[i].first and c[j].second != c[i].second)
				p++;
			if (c[j].first != c[i].first and c[j].second == c[i].second)
				q++;

			if (p == 3 or q == 3)
				f = 1;
		}
	}

	sort(c, c + n);

	if (!f)
	{
		for (int i = 0; i < n and !f; i++)
			for (int j = i + 1; j < n and !f; j++)
				for (int k = j + 1; k < n and !f; k++)
				{
					double  p = c[i].first - c[j].first, q = c[j].first - c[k].first;
					double  x = c[i].second - c[j].second, y = c[j].second - c[k].second;

					double b = q / p;
					double bb = x * b;

					if (bb == y)
						f = 1;
				}
	}

	cout << (f ? "Yes" : "No") << '\n';
}