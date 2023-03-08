#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

//const ll N = 2e3, mod1 = 1055482763, base1 = 1055476621, mod2 = 2113605293, base2 = 2049246427;
const ll N = 50005, M = 205, mod1 = 2e9 + 87, mod2 = mod1, base1 = 1e9 + 33, base2 = 1e9 + 181;
//const ll N = 2e3, mod1 = 1055482763, mod2 = mod1, base1 = 1055476621, base2 = 189343181;

ll ht1[N][M], ht2[N][M], power1[N], power2[N];

void powc()
{
	power1[0] = power2[0] = 1;

	for (int i = 1; i < N; i++)
		power1[i] = (power1[i - 1] * base1) % mod1;
	for (int i = 1; i < N; i++)
		power2[i] = (power2[i - 1] * base2) % mod2;
}

ll Hash(string const &s)
{
	ll n = (ll) s.size(), x = 0LL, y = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base1) + s[i]) % mod1;
	for (ll i = 0; i < n; i++)
		y = ((x * base2) + s[i]) % mod2;

	return (x << 32) | y;
}

ll  hash_val(int i, int l, int r)
{
	ll x = (ht1[i][r] - (ht1[i][l - 1] * power1[r - l + 1])) % mod1;
	ll y = (ht2[i][r] - (ht2[i][l - 1] * power2[r - l + 1])) % mod2;
	if (x < 0) x += mod1;
	if (y < 0) y += mod2;

	return (x << 32) | y;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n; cin >> n;
		string s[n];

		for (int i = 0; i < n; i++)
			cin >> s[i];

		sort(s, s + n);

		for (int i = 0; i < n; i++)
		{
			int m = s[i].size();
			for (int j = 1; j <= m; j++)
			{
				ht1[i][j] = ((ht1[i][j - 1] * base1) + s[i][j - 1]) % mod1;
				ht2[i][j] = ((ht2[i][j - 1] * base2) + s[i][j - 1]) % mod2;
			}
		}

		ll ans = 0, t = 1, pre = 0;
		unordered_map <ll, ll> cnt;

		for (int i = 0; i < n; i++)
		{
			ll m = s[i].size();
			for (int j = 1; j <= m; j++)
			{
				ll x = hash_val(i, 1, j);

				cnt[x]++;
				ll y = cnt[x];

				//cout << x << ' ' <<

				ans = max(ans, y * j);
			}
		}

		cout << ans << '\n';
	}
}