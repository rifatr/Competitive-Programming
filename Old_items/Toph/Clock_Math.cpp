#include <bits/stdc++.h>

using namespace std;

int main()
{
	double h, m, ha, ma;

	cin >> h >> m;

	ha = h * 30;

	ha += (m / 60) * 30;

	ma = m * 6;

	double ans = ha - ma;

	if(ans > 180.0)
		ans = 360 - ans;

	cout << fixed << setprecision(4) << abs(ans) << endl;

	return 0;
}