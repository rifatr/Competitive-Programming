#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 46342;

ll power(ll a, ll b)
{
	ll x = a;
	for (ll i = 1; i < b; i++)
		x *= a;

	return x;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int z = 1; z <= t; z++)
	{
		ll n, ans = 0LL;
		scanf("%lld", &n);

		for (ll i = 2; !ans and i <= min(N, n); i++)
		{
			ll x = 0;
			for (ll j = 1; x < n and !ans; j++)
			{
				x = power(i, j);
				if (x == n) {
					ans = j;
					break;
				}
			}
		}

		if (!ans) ans = 1LL;

		printf("Case %d: %lld\n", z, ans);
	}
	return 0;
}
