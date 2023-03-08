#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 50005, M = 60, mod1 = 2e9 + 87, mod2 = mod1, base1 = 1e9 + 33, base2 = 1e9 + 181;

ll ht1[M], ht2[M], power1[N], power2[N];
char s[M];

void powc()
{
	power1[0] = power2[0] = 1;

	for (int i = 1; i < N; i++)
		power1[i] = (power1[i - 1] * base1) % mod1;
	for (int i = 1; i < N; i++)
		power2[i] = (power2[i - 1] * base2) % mod2;
}

ll  hash_val(int l, int r)
{
	ll x = (ht1[r] - (ht1[l - 1] * power1[r - l + 1])) % mod1;
	ll y = (ht2[r] - (ht2[l - 1] * power2[r - l + 1])) % mod2;
	if (x < 0) x += mod1;
	if (y < 0) y += mod2;

	return (x << 32) | y;
}

int main()
{
	powc();
	int t, tt = 1;
	scanf("%d", &t);

	while (t--)
	{
		int n; scanf("%d", &n);

		ll ans = 0;
		unordered_map <ll, ll> cnt;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			for (int j = 1; s[j - 1] != '\0'; j++)
			{
				ht1[j] = ((ht1[j - 1] * base1) + s[j - 1]) % mod1;
				ht2[j] = ((ht2[j - 1] * base2) + s[j - 1]) % mod2;
			}
			for (int j = 1; s[j - 1] != '\0'; j++)
			{
				ll x = hash_val(1, j);

				cnt[x]++;
				ll y = cnt[x];

				ans = max(ans, y * j);
			}
		}

		printf("Case %d: %lld\n", tt++, ans);
	}

	return 0;
}