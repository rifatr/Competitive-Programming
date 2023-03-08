#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, mx[3], mn[3], deg[3];

	cin >> n;

	for (int i = 0; i < 3; i++)
		cin >> mn[i] >> mx[i], deg[i] = mn[i], n -= deg[i];

	for (int i = 0; i < 3 and n; i++)
	{
		int z = min(n, mx[i] - mn[i]);
		deg[i] += z;
		n -= z;
	}

	for (int i = 0; i < 3; i++)
		cout << deg[i] << ' ';

	return 0;
}