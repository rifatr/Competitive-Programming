#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;

	for (int z = 1; z <= t; z++)
	{
		int n; cin >> n;
		int a[n + 1], pos[n + 1], c = 0;

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			pos[a[i]] = i;
		}

		bool vis[n + 1] = {0};

		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) continue;

			int p = a[i];
			while (1)
			{
				if (vis[p]) break;

				vis[p] = 1;
				p = pos[p];
				c++;
			}
			c--;
		}

		cout << "Case " << z << ": " << c << '\n';
	}
	return 0;
}