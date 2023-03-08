#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

void solve();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin)

	int test = 1;

	// cin >> test;

	while (test--)
	{
		solve();
	}

	return 0;
}

void solve()
{
	int n;
	cin >> n;

	ll a[n], s = 0, ans = (1LL << 60);
	lop(n) cin >> a[i], s += a[i];

	for (int i = 0; i < (1 << n); i++)
	{
		ll x = 0;
		loop(j, 0, n) if (i & (1 << j)) x += a[j];

		ans = min(ans, abs(x - (s - x)));
	}

	cout << ans;
	return;
}