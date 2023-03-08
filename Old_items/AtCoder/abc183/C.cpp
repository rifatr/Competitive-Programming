#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	ll k;
	cin >> n >> k;
	ll a[n][n];
	lop(n) loop(j, 0, n) cin >> a[i][j];

	int tra[n + 1];
	tra[0] = tra[n] = 0;
	loop(i, 1, n) tra[i] = i;

	ll ans = 0;

	do
	{
		ll tmp = 0;
		lop(n) tmp += a[tra[i]][tra[i + 1]];
		lop(n + 1) cout << tra[i] << ' ';
		cout << '\n';
		cout << tmp << '\n';

		ans += (tmp == k);
	}
	while (next_permutation(tra + 1, tra + n));


	cout << ans << '\n';

	return 0;
}
