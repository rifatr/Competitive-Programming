#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll rnd(ll a, ll b)
{
	return a + rand() % (b - a + 1);
}

ll mx = (1LL << 31) - 1, mn = 1, d = 1e5;

int main(int argc, char const *argv[])
{
	int t = rnd(1LL, 100LL);
	cout << t << '\n';
	while (t--)
	{
		ll a = rnd(mn, mx), b = rnd(a, a + d);
		//if (a > b) swap(a, b);
		cout << a << ' ' << b << '\n';
	}
	return 0;
}