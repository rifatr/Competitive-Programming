#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 2e3, mod = 1055482763, base = 1055476621, mod2 = 2113605293, base2 = 2049246427;

ll Hash(string const &s)
{
	ll n = (ll) s.size(), x = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base) + s[i]) % mod;

	return x;
}

bool prefix(string const &s, string const &t)
{
	if (t.size() < s.size())
		return 0;

	ll y = Hash(s);
	ll n = (ll) t.size(), x = 0LL;
	for (ll i = 0; i < n; i++)
	{
		x = ((x * base) + t[i]) % mod;
		if (x == y)
            return 1;
	}

	return 0;
}

int main()
{
	int t, tt = 1;
	cin >> t;

	while (t--)
	{
	    cout << "Case " << tt++ << ": ";
		int n;
		cin >> n;

		string num[n];

		for (int i = 0; i < n; i++)
			cin >> num[i];

		sort(num, num + n);

		string res = "YES";
		for (int i = 0; i < n - 1; i++)
		{
			if (prefix(num[i], num[i + 1]))
			{
				res = "NO";
				break;
			}
		}

		cout << res << '\n';
	}

	return 0;
}
