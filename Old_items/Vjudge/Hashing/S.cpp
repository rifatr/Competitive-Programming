#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef long long ll;

const ll N = 1e5 + 5, mod1 = 2e9 + 87, mod2 = mod1, base1 = 1e9 + 33,  base2 = 1e9 + 181;

unordered_map <ll, int> pref, sub;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m, x, y, z;
	cin >> n;
	string num[n];

	for (ll i = 0; i < n; i++)
		cin >> num[i];

	for (ll i = 0; i < n; i++)
	{
		m = num[i].size(), x = 0LL, y = 0LL;
		for (int j = 0; j < m; j++)
		{
			x = ((x * base1) + num[i][j]) % mod1;
			y = ((y * base2) + num[i][j]) % mod2;
			z = (x << 32) | y;

			if (pref[z])
			{
				cout << "BAD SET\n" << num[i] << '\n';
				return 0;
			}

			sub[z]++;
		}

		pref[z]++;
		if (sub[z] > 1)
		{
			cout << "BAD SET\n" << num[i] << '\n';
			return 0;
		}
	}

	cout << "GOOD SET\n";

	return 0;
}