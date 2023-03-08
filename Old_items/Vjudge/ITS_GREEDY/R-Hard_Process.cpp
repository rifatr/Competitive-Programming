#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	bool a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int c, l, r, j;
	c = l = r = j = 0;

	for (int i = 0; i < n; i++)
	{
		if (j < i)
			j = i, c = 0;

		for (; j < n; j++)
		{
			if (c + !a[j] > k)
				break;

			c += !a[j];
		}

		if (j - i > r - l)
			l = i, r = j;

		if (c > 0)
			c -= !a[i];
	}

	cout << r - l << endl;
	for (int i = 0; i < n; ++i)
	{
		if (i >= l and i < r)
			cout << 1 << ' ';
		else
			cout << a[i] << ' ';
	}

	cout << endl;

	return 0;
}