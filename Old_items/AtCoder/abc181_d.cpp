#include <bits/stdc++.h>

using namespace std;

int div8[130], z, c[10];


int stroin(string s)
{
	int x = 0, n = s.size();

	for (int i = 0; i < n; i++)
	{
		x *= 10;
		x += (s[i] - '0');
	}

	return x;
}

int main()
{
	for (int z = 1; z < 125; z++)
		div8[z] = z * 8;

	int n;
	string s;

	cin >> s; n = s.size();

	if (n <= 3)
	{
		sort(s.begin(), s.end());
		do
		{
			int x = stroin(s);
			if (x % 8 == 0) {
				cout << "Yes\n";

				return 0;
			}
		}
		while (next_permutation(s.begin(), s.end()));

		cout << "No\n";

		return 0;
	}

	for (int i = 0; i < n; i++)
		c[s[i] - '0']++;

	int f = 0;
	for (int i = 13; i < 125; i++)
	{
		int cc[10] = {0};
		int x = div8[i];

		while (x)
		{
			cc[x % 10]++;
			x /= 10;
		}

		int pp = 0, qq = 0;
		for (int k = 0; k < 10; k++)
			if (cc[k])
			{
				pp++;
				if (c[k] >= cc[k])
					qq++;
			}

		if (pp and qq and pp == qq)
		{
			f = 1;
			break;
		}
	}

	cout << (f ? "Yes" : "No") << '\n';
	return 0;
}