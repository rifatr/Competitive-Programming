#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 23, mod1 = 1055482763, base1 = 1051, mod2 = 2113605293, base2 = 1337;
ll ht1[N], ht2[N];
char s[N];

ll power(ll n, ll x, ll mod)
{
	if (x == 0LL)
		return 1LL;

	ll p = 1LL;
	while (x--)
		p = (p * n) % mod;

	return p;
}

int main()
{
	int k, nc;
	scanf("%d %d %s", &k, &nc, s);
	int n = strlen(s);

	for (int i = 1; i <= n; i++)
	{
		ht1[i] = ((ht1[i - 1] * base1) + s[i - 1]) % mod1;
		ht2[i] = ((ht2[i - 1] * base2) + s[i - 1]) % mod2;
	}

	vector <ll> st;
	ll pwr1 = power(base1, k, mod1), pwr2 = power(base2, k, mod2);

	for (int i = k; i <= n; i++)
	{
		ll x = (ht1[i] - (ht1[i - k] * pwr1)) %  mod1;
		ll y = (ht2[i] - (ht2[i - k] * pwr2)) %  mod2;
		if (x < 0LL) x += mod1;
		if (y < 0LL) y += mod2;
		ll z = (x << 32) | y;

		st.push_back(z);
	}

	sort(st.begin(), st.end());
	int ans = 1, lm = st.size();
	for (int i = 0; i < lm - 1; i++)
		if (st[i] != st[i + 1])
			ans++;
	if (lm == 0) ans = 0;

	printf("%d\n", ans);

	return 0;
}