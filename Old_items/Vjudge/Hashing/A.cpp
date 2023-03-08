#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 123, base = 1e9 + 7;

ll Hash(string s)
{
	ll n = (ll) s.size(), x = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base) + s[i]) % mod;

	return x;
}

bool prefix(string s, string t)
{
	if (t.size() < s.size())
		return 0;

	// cout << "here " << s << ' ' << t << '\n';

	ll y = Hash(s);
	ll n = (ll) t.size(), x = 0LL;
	for (ll i = 0; i < n; i++)
	{
		x = ((x * base) + t[i]) % mod;
		// cout << y << ' ' << x << '\n';
		if (x == y)
		{
			// cout << "break " << ' ' << i << '\n';
			return 1;
		}
	}

	return 0;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector <string> num(n);

		for (int i = 0; i < n; i++)
			cin >> num[i];

		sort(num.begin(), num.end());

		string res = "YES";
		for (int i = 0; i < n - 1; i++)
		{
			if (prefix(num[i], num[i + 1]))
			{
				// cout << "no " << num[i] << ' ' << num[i + 1] << '\n';
				res = "NO";
				break;
			}
		}

		cout << res << '\n';
	}

	return 0;
}