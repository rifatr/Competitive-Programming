#include <bits/stdc++.h>

using namespace std;
using namespace chrono;


typedef long long ll;

const ll N = 50005, M = 30, mod1 = 1e9 + 7, mod2 = mod1, base1 = 27, base2 = 29;
ll ht1[M], ht2[M], power1[M], power2[M];

void powc()
{
	power1[0] = power2[0] = 1;

	for (int i = 1; i < M; i++)
		power1[i] = (power1[i - 1] * base1) % mod1;
	for (int i = 1; i < M; i++)
		power2[i] = (power2[i - 1] * base2) % mod2;
}

ll Hash(string &s)
{
	ll n = (ll) s.size(), x = 0LL, y = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base1) + s[i] - 96) % mod1;
	for (ll i = 0; i < n; i++)
		y = ((y * base2) + s[i] - 96) % mod2;

	//cout << s << ' ' << x << ' ' << y << '\n';
	return (x << 32) | y;
}

ll  hash_val(int l, int r)
{
	ll x = (ht1[r] - (ht1[l - 1] * power1[r - l + 1])) % mod1;
	ll y = (ht2[r] - (ht2[l - 1] * power2[r - l + 1])) % mod2;
	if (x < 0) x += mod1;
	if (y < 0) y += mod2;

	return (x << 32) | y;
}

unordered_map <ll, ll> cnt;
unordered_map <ll, bool> vis;
int main()
{
#ifndef ONLINE_JUDGE
	auto start = high_resolution_clock::now();
	freopen("/home/rifat/input.txt", "r", stdin);
	freopen("/home/rifat/output.txt", "w", stdout);
#endif

	powc();

	int n; cin >> n;
	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int m = s.size();

		for (int j = 1; s[j - 1] != '\0'; j++)
		{
			ht1[j] = ((ht1[j - 1] * base1) + s[j - 1] - 96) % mod1;
			ht2[j] = ((ht2[j - 1] * base2) + s[j - 1] - 96) % mod2;
		}

		for (int j = 1; s[j - 1] != '\0'; j++)
		{
			for (int k = j; s[k - 1] != '\0'; k++)
			{
				ll x = hash_val(j, k);

				if (!vis[x])
				{
					cnt[x]++;
					vis[x] = 1;
					//cout << s.substr(j - 1, k - j + 1) << ' ' << x << '\n';
				}

				//cout << s.substr(j - 1, k - j + 1) << ' ' << cnt[x] << '\n';
			}
		}

		vis.clear();
	}

	int q; cin >> q;
	while (q--)
	{
		cin >> s;

		ll x = Hash(s);
		//cout << s << ' ' <<  x << ' ';
		cout << cnt[x] << '\n';
	}

#ifndef ONLINE_JUDGE
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "\nTime: " << duration.count() << "ms" << endl;
#endif

	return 0;
}