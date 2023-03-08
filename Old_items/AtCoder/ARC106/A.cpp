#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
	auto start = high_resolution_clock::now();
	freopen("/home/rifat/input.txt", "r", stdin);
	freopen("/home/rifat/output.txt", "w", stdout);
#endif

	ll n;

	cin >> n;

	for (ll i = 0; i <= 38; i++)
	{
		ll x;
		for (ll j = 0; j < 26; j++)
		{
			x = pow(3, i) + pow(5, j);

			if (x == n)
			{
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;


#ifndef ONLINE_JUDGE
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "\nTime: " << duration.count() << "ms" << endl;
#endif

	return 0;
}