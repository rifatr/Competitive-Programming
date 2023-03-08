#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll mod = 1e9 + 123, base = 1e9 + 7;
map <ll, ll> pt;

ll Hash(string s)
{
	ll n = (ll) s.size(), x = 0LL;

	for (ll i = 0; i < n; i++)
		x = (x * base) + (s[i] - 96);

	return x;
}

int main()
{
	ll n;
	string nm;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nm;
		ll x = Hash(nm);

		if (!pt[x])
			cout << "OK\n";
		else
			cout << nm << pt[x] << '\n';

		pt[x]++;
	}

	return 0;
}