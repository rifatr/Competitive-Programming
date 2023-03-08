#include <bits/stdc++.h>

using namespace std;
using namespace chrono;


typedef long long ll;

const ll N = 1e6 + 5, mod1 = 2e9 + 87, mod2 = mod1, base1 = 1e9 + 33,  base2 = 1e9 + 181;
ll ht1[N], ht2[N], power1[N], power2[N];
char hs[N], s[N];

void powc()
{
	power1[0] = power2[0] = 1;

	for (int i = 1; i < N; i++)
	{
		power1[i] = (power1[i - 1] * base1) % mod1;
		power2[i] = (power2[i - 1] * base2) % mod2;
	}

}

ll Hash()
{
	ll x = 0LL, y = 0LL;

	for (ll i = 0; s[i] != '\0'; i++)
	{
		x = ((x * base1) + s[i]) % mod1;
		y = ((y * base2) + s[i]) % mod2;
	}

	//cout << s << ' ' << x << ' ' << y << '\n';
	return (x << 32) | y;
}

ll  hash_val(int l, int r)
{
	ll x = (ht1[r] - (ht1[l] * power1[r - l])) % mod1;
	ll y = (ht2[r] - (ht2[l] * power2[r - l])) % mod2;
	if (x < 0) x += mod1;
	if (y < 0) y += mod2;

	return (x << 32) | y;
}

int main()
{
#ifndef ONLINE_JUDGE
	auto start = high_resolution_clock::now();
	freopen("/home/rifat/input.txt", "r", stdin);
	freopen("/home/rifat/output.txt", "w", stdout);
#endif

	powc();

	int n;
	while (scanf("%d", &n) == 1)
	{
		scanf(" %s %s", s, hs);

		//cout << n << ' ' << s << ' ' << hs << '\n';

		int a = strlen(hs);
		if (a < n)
		{
			printf("\n");
			continue;
		}
		for (int i = 1; hs[i - 1] != '\0'; i++)
		{
			ht1[i] = ((ht1[i - 1] * base1) + hs[i - 1]) % mod1;
			ht2[i] = ((ht2[i - 1] * base2) + hs[i - 1]) % mod2;
		}

		ll H = Hash();
		for (int i = n; hs[i - 1] != '\0'; i++)
		{
			ll x = hash_val(i - n, i);
			//cout << H << ' ' << x << '\n';

			if (x == H)
				printf("%d\n", i - n);
		}
		printf("\n");

	}

#ifndef ONLINE_JUDGE
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "\nTime: " << duration.count() << "ms" << endl;
#endif

	return 0;
}