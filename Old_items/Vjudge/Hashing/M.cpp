#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 123, base = 1e9 + 7;

ll power(ll n, ll x)
{
	if (x == 0)
		return 1;

	ll p = 1LL;
	while (x--)
		p = (p * n) % mod;

	return p;
}

ll Hash(string s)
{
	ll n = (ll) s.size(), x = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base) + s[i]) % mod;

	return x;
}

int main()
{
	string s, t;
	cin >> s >> t;

	int n = s.size(), m = t.size();
	ll ht[n + 1] = {0}, H = Hash(t);

	for (int i = 1; i <= n; i++)
	{
		ht[i] = ((ht[i - 1] * base) + s[i - 1]) % mod;
	}

	ll pwr = power(base, m);
	for (int i = m; i <= n; i++)
	{
		ll x = (ht[i] - (ht[i - m] * pwr)) % mod;
		if (x < 0) x += mod;

		if (x == H)
			cout << i - m << '\n';
	}

	return 0;
}