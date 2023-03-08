#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;

	for (int z = 1; z <= t; z++)
	{
		int n; cin >> n;
		int a[n], b[n], c = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];

		sort(a, a + n);
		sort(b, b + n);

		for (int i = 0; i < n; i++)
		{
			if (a[i] == -1) continue;;

			for (int j = 0; j < n; j++)
			{
				if (b[j] == -1) continue;
				if (a[i] < b[j]) break;

				if (b[j] <= a[i])
				{
					if (b[j] == a[i])
					{
						bool f = 1, vis[n] = {0};
						for (int k = i + 1; k < n and f; k++)
						{
							if (a[k] == -1 or a[k] == a[i]) continue;
							for (int l = j + 1; l < n and f; l++)
							{
								if (b[l] == -1 or vis[l]) continue;

								vis[l] = 1;

								if (a[k] <= b[l])
								{
									f = 0;
									c += 2;
									a[k] = -1;
								}
								else
									break;
							}
						}

						if (f) c++;
					}
					else c += 2;

					b[j] = -1;
					break;
				}
			}
		}

		cout << "Case " << z << ": " << c << '\n';
	}
	return 0;
}