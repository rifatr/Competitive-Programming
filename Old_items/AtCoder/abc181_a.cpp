#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ll n, a, b;

	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		a--;

		sum += (b * (b + 1) / 2) - (a * (a + 1) / 2);
	}

	cout << sum << '\n';
}