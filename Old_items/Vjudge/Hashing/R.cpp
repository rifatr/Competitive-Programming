#include <bits/stdc++.h>

using namespace std;
using namespace chrono;


typedef long long ll;

const ll N = 1e5 + 5, mod1 = 1611623773, mod2 = 2105547079, base1 = 179424673,  base2 = 982451653;

ll Hash(string const &s)
{
	ll x = 0LL, y = 0LL;

	for (ll i = 0; s[i] != '\0'; i++)
	{
		x = ((x * base1) + s[i]) % mod1;
		y = ((y * base2) + s[i]) % mod2;
	}

	return (x << 32) | y;
}

unordered_map <ll, ll> cnt;
int main()
{
#ifndef ONLINE_JUDGE
	auto start = high_resolution_clock::now();
	freopen("/home/rifat/input.txt", "r", stdin);
	freopen("/home/rifat/output.txt", "w", stdout);
#endif

	int n;
	string s, cmnd;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cmnd >> s;

		if (cmnd == "add")
		{
			ll x, y, j;
			x = y = j = 0;

			while (s[j] != '\0')
			{
				x = ((x * base1) + s[j]) % mod1;
				y = ((y * base2) + s[j]) % mod2;
				ll z = (x << 32) | y;

				cnt[z]++;
				j++;
			}
		}

		else
		{
			ll x = Hash(s);
			cout << cnt[x] << '\n';
		}

	}

#ifndef ONLINE_JUDGE
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "\nTime: " << duration.count() << "ms" << endl;
#endif

	return 0;
}