#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 3e5 + 6;
ll n, a[N], q;

void edit(ll x, int ind)
{
	while (ind <= n)
	{
		a[ind] ^= x;

		ind += (ind & -ind);
	}
}

ll sum(int ind)
{
	ll s = 0;

	while (ind)
	{
		s ^= a[ind];

		ind -= (ind & -ind);
	}

	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	int p;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		edit(p, i);
	}

	while (q--)
	{
		int op, x, y;
		cin >> op >> x >> y;

		if (op == 1)
			edit(y, x);
		else
		{
			ll u = sum(y), v = sum(x - 1);
			cout << (u ^ v) << '\n';
		}
	}

	return 0;
}