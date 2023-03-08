#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 8;
int a[N];

void edit(int x)
{
	while (x < N)
	{
		a[x]++;

		x += x & -x;
	}
}

int cnt(int x)
{
	int s = 0;
	while (x)
	{
		s += a[x];

		x -= x & -x;
	}

	return s;
}

int main()
{
	int n, b, i = 0, c = 0;
	cin >> n;

	while (i++ < n)
	{
		cin >> b;
		cout << cnt(n) << ' ' << cnt(b - 1) << ' ' << c << '\n';
		c += cnt(n) - cnt(b - 1);
		edit(b);

		// cout << cnt(n) << ' ' << cnt(b - 1) << ' ' << c << '\n';

		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}

	cout << c << '\n';
}