#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define ff first
#define ss second
#define pld pair <ld, ld>
#define pll pair <ll, ll>

inline ll sq(ll x) {return x * x;}
// inline ld sq(ld x) {return x * x;}
inline ld dis(pll &a, pll &b) {return sqrt((ld) sq(a.ff - b.ff) + (ld)sq(a.ss - b.ss));}
// inline ld MIN(ld &x, ld &y) {}

const ll N = 1e3 + 12, inf = 1e18;
ll n, v1, v2;
ld dp[N][N];
bool vis[N][N];
pll g[N], s, d;

bool comp(pll &a, pll &b) {
	ll d1 = sq(g[0].ff - a.ff) + sq(g[0].ss - a.ss);
	ll d2 = sq(g[0].ff - b.ff) + sq(g[0].ss - b.ss);

	return d1 < d2;
}

ld TIME(int i, int j) {
	ld ds = dis(g[i], g[j]);
	if (i == 0) return ds / v1;
	if (v2 * 3 >= (ll) ceil(ds)) return ds / v2;

	// cout << ds << ' ' << v2 * 3 << '\n';
	ds -= v2 * 3;
	// cout << ds << ' ' << ds / v1 << '\n';

	return 3 + (ds / v1);
}

ld rfs(int i, int j) {
	if (j == n + 1) return TIME(i, j);
	if (vis[i][j]) return dp[i][j];
	vis[i][j] = 1;

	dp[i][j] = rfs(i, j + 1);
	ld x = rfs(j, j + 1) + TIME(i, j);
	// cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << x << '\n';

	return dp[i][j] = min(dp[i][j], x);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> g[i].ff >> g[i].ss;
	cin >> g[0].ff >> g[0].ss >> g[n + 1].ff >> g[n + 1].ss >> v1 >> v2;
	sort(g + 1, g + n + 1, comp);

	// for (int i = 0; i <= n + 1; i++) cout << g[i].ff << ' ' << g[i].ss << '\n';
	// cout << "\n";

	ld ans = rfs(0, 1);
	cout << fixed << setprecision(8) << ans << '\n';

	// cout << TIME(1, 2);
}