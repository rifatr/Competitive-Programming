#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e4 + 5, M = 101, mod1 = 2e9 + 87, mod2 = mod1, base1 = 1e9 + 33,  base2 = 1e9 + 181;
char s[M], sss[N];

/*ll Hash()
{
	ll x = 0LL, y = 0LL;
	int ct[60] = {0}, n = strlen(s);
	for (int i = 1; i < n - 1; i++)
		ct[s[i] - 'A']++;

	x = ((x * base1) + s[0]) % mod1;
	y = ((y * base2) + s[0]) % mod2;
	for (int i = 0; i < 60; i++)
	{
		int p = ct[i];
		while (p--)
		{
			x = ((x * base1) + ('A' + i)) % mod1;
			y = ((y * base2) + ('A' + i)) % mod2;
		}
	}
	x = ((x * base1) + s[n - 1]) % mod1;
	y = ((y * base2) + s[n - 1]) % mod2;

	return (x << 32) | y;
}*/

ll Hash()
{
	int ct[60] = {0}, n = strlen(s);
	for (int i = 1; i < n - 1; i++)
		ct[s[i] - 'A']++;

	ll x = s[0] % mod1;
	for (int i = 0; i < 60; i++)
	{
		int p = ct[i];
		while (p--)
		{
			x = ((x * base1) + ('A' + i)) % mod1;
		}
	}
	x = ((x * base1) + s[n - 1]) % mod1;

	return x;
}

unordered_map <ll, int> cnt;

int main()
{
	int t, tt = 1;
	scanf("%d", &t);

	while (t--)
	{
		printf("Case %d:\n", tt++);

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf(" %s", s);
			ll x = Hash();
			cnt[x]++;

			//cout << s << ' ' << x << ' ' << cnt[x] << '\n';
		}

		int q;
		scanf("%d ", &q);
		while (q--)
		{
			int ans = 1, i = 0;
			scanf("%[^\n]s", sss);

			for (int k = 0; sss[k] != '\0'; k++)
			{
				if (sss[k] == ' ')
				{
					if (i == 0) continue;

					s[i] = '\0';
					ans *= cnt[Hash()];
					i = 0;
				}
				else
					s[i++] = sss[k];

				//printf("%d %s\n", i, s);
			}
			s[i] = '\0';
			ans *= cnt[Hash()];
			printf("%d\n", ans);
		}
	}

	return 0;
}