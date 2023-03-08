#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a, pos[n + 1] = {0}, ans = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		pos[a] = pos[a - 1] + 1;
		ans = max(ans, pos[a]);
	}

	cout << n - ans << '\n';

	return 0;
}