#include<bits/stdc++.h>

using namespace std;

#define lop(n) for(int i = 0; i < n; i++)

int main()
{
	string s, t;
	cin >> s;
	int n = s.size(), c[26] = {0};

	lop(n) c[s[i] - 'A']++;

	int x = 0;
	lop(26) x += (c[i] & 1);

	if (x > 1)
		t = "NO SOLUTION\n";
	else
	{
		int p = 0, q;
		for (int j = 0; j < 26; ++j)
		{
			if (c[j] & 1)
			{
				p = c[j];
				q = j;
				c[j] = 0;
			}
			else
				lop(c[j] / 2) t.push_back('A' + j);
		}

		lop(p) t.push_back('A' + q);

		for (int j = 25; j >= 0; j--)
			lop(c[j] / 2) t.push_back('A' + j);
	}

	cout << t << '\n';
	return 0;
}