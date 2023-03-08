#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

const int N = 1e5 + 9;
ll n, q, a[N], bit[N], phi[N];

void phi_sieve();

void edit(int pos, int val)
{
	while (pos <= n)
	{
		bit[pos] += val;
		pos += pos & -pos;
	}
}

ll sum(int pos)
{
	ll s = 0;
	while (pos)
	{
		s += bit[pos];
		pos -= pos & -pos;
	}

	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	phi_sieve();

	cin >> n >> q;

	lop(n)
	{
		cin >> a[i];
		edit(i + 1, phi[a[i]]);
	}

	while (q--)
	{
		int op, l, r;
		cin >> op >> l >> r;

		if (op == 1)
		{
			edit(l, -phi[a[l - 1]]);
			a[l - 1] = r;
			edit(l, phi[r]);
		}
		else
		{
			cout << sum(r) - sum(l - 1) << '\n';
		}
	}
}

void phi_sieve()
{
	for (int i = 0; i < N; i++)
		phi[i] = i;

	for (int i = 2; i <= N; i++)
	{
		if (phi[i] == i)
		{
			phi[i] = i - 1;

			for (ll j = 2 * i; j <= N; j += i)
				phi[j] = (phi[j] / i) * (i - 1);
		}
	}
}