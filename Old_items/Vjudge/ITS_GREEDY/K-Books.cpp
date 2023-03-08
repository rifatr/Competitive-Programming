#include <bits/stdc++.h>

using namespace std;

#define close(x) {cout << x; return 0;}

int main()
{
	int n; cin >> n;
	long long t; cin >> t;

	long long a[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i], a[i] += a[i - 1];

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int z = upper_bound(a + 1, a + n + 1, t + a[i - 1]) - a;
		ans = max(ans, z - i);
	}

	close(ans);
}