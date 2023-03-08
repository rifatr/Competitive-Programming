#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5 + 6;
ll n, a[N], q;

void edit(int ind, ll x)
{
	while (ind <= n)
	{
		a[ind] += x;

		ind += (ind & -ind);
	}
}

void update(int l, int r, int c)
{
	edit(l, c);
	edit(r + 1, -c);
}

ll query(int ind)
{
	ll s = 0;

	while (ind)
	{
		s += a[ind];

		ind -= (ind & -ind);
	}

	return s;
}

int main()
{
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		int p; cin >> p;
		update(i, i, p); // a[i] = p
	}

	while (q--)
	{
		int op; cin >> op;

		if (op == 1)
		{
			int a, b, x;
			cin >> a >> b >> x;

			update(a, b, x); // increase a[l, r] by x
		}
		else
		{
			int x; cin >> x;
			cout << query(x) << '\n'; // print a[x]
		}
	}

	return 0;
}
