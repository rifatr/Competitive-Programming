#include <bits/stdc++.h>

using namespace std;

#define bug(i) cout << i << '\n';

typedef long long ll;

const int N = 1e5 + 5;
const ll mod = 1e6 + 7;
ll a[N];

int main()
{
	int tt, t = 1; scanf("%d", &tt);

	while (tt--)
	{
		ll k, n, c;

		scanf("%lld %lld %lld %lld", &k, &c, &n, &a[0]);

		for (int i = 1; i < n; i++)
			a[i] = (k * a[i - 1] + c) % mod;

		sort(a, a + n);

		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += (a[i] * i) - (a[i] * (n - i - 1));

		printf("Case %d: %lld\n", t++, sum);
	}
	return 0;
}