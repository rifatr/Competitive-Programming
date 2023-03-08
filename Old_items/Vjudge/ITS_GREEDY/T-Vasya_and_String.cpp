#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int c, l, r, j;

	c = l = r = j = 0;
	for (int i = 0; i < n; i++)
	{
		if (j < i)
			j = i, c = 0;

		for (; j < n; j++)
		{
			if (c + (s[j] == 'b') > k)
				break;

			c += (s[j] == 'b');
		}

		if (j - i > r - l)
			l = i, r = j;

		if (c > 0)
			c -= (s[i] == 'b');
	}

	int ans = r - l;

	c = l = r = j = 0;
	for (int i = 0; i < n; i++)
	{
		if (j < i)
			j = i, c = 0;

		for (; j < n; j++)
		{
			if (c + (s[j] == 'a') > k)
				break;

			c += (s[j] == 'a');
		}

		if (j - i > r - l)
			l = i, r = j;

		if (c > 0)
			c -= (s[i] == 'a');
	}

	cout << max(ans, r - l) << endl;

	return 0;
}