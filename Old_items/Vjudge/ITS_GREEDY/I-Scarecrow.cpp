#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;

	for (int z = 1; z <= t; z++)
	{
		int n, c = 0;
		string s;

		cin >> n >> s;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '.')
			{
				c++;
				i += 2;
			}
		}

		cout << "Case " << z << ": " << c << '\n';
	}
	return 0;
}