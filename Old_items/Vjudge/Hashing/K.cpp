#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 2e3, mod1 = 1055482763, base1 = 1055476621, mod2 = 2113605293, base2 = 2049246427;
//const ll N = 2e3, mod1 = 2e9+87, mod2 = mod1, base1 = 1e9+33, base2 = 1e9+181;
//const ll N = 2e3, mod1 = 1055482763, mod2 = mod1, base1 = 1055476621, base2 = 189343181;

ll ht1[N], ht2[N], power1[N], power2[N];

void powc()
{
	power1[0] = power2[0] = 1;

	for (int i = 1; i < N; i++)
		power1[i] = (power1[i - 1] * base1) % mod1;
    for (int i = 1; i < N; i++)
		power2[i] = (power2[i - 1] * base2) % mod2;
}

/*ll Hash(string &s)
{
	ll n = (ll) s.size(), x = 0LL, y = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base1) + s[i]) % mod1;
    for (ll i = 0; i < n; i++)
		y = ((x * base2) + s[i]) % mod2;

	return (x << 32) | y;
}*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	string s, bd;
	cin >> s >> bd >> k;
	int n = s.size();

	for (int i = 1; i <= n; i++)
	{
		ht1[i] = ((ht1[i - 1] * base1) + s[i - 1]) % mod1;
		ht2[i] = ((ht2[i - 1] * base2) + s[i - 1]) % mod2;

		//ht[i] = (x << 32) | y;
	}

	powc();
	unordered_set <ll> st;

	for (int i = 1; i <= n; i++)
	{
		string t = "";
		int b = 0;
		for (int j = i; j <= n; j++)
		{
			t.push_back(s[j - 1]);
			b += (bd[s[j - 1] - 'a'] == '0');

			if (b > k) break;

			ll x = (ht1[j] - (ht1[i - 1] * power1[j - i + 1])) %  mod1;
			ll y = (ht2[j] - (ht2[i - 1] * power2[j - i + 1])) %  mod2;
			if (x < 0) x += mod1;
			if (y < 0) y += mod2;
			ll z = (x << 32) | y;

//			cout << t << ' ' << z << ' ' << Hash(t) << '\n';

			st.insert(z);
		}
	}

	cout << st.size() << '\n';

	return 0;
}

