#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)
#define loop(i, a, b) for (int i = a; i < b; i++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifdef rifat
#include <debug.hpp>
#else
#define dbg(x)
#define ddbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll N = 4e4 + 10, mod = 1e9 + 7;
ll dp[N][500];
vin pali;

bool ispal(int x) {
	vin vv;
	while (x) {
		vv.pb(x % 10);
		x /= 10;
	}

	int i = 0, j = (int) vv.size() - 1;
	while (i < j) {
		if (vv[i] != vv[j]) return 0;
		i++, j--;
	}
	return 1;
}

ll rfs(int i, int j) {
	if (i == 0) return 1;
	if (i < 0 or j == pali.size() or i < pali[j]) return 0;
	ll &x = dp[i][j];
	if (~x) return x;

	x = 0;
	x += rfs(i - pali[j], j);
	x += rfs(i, j + 1);
	// dbg3(i, j, x)

	return x %= mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	lop(N) if (ispal(i + 1)) pali.pb(i + 1);
	memset(dp, -1, sizeof dp);
	// for (int i = N - 1; i > 0; i--)
	// 	rfs(i, 0);
	// ddbg(dp)

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n; cin >> n;
		print(rfs(n, 0));
	}

	return 0;
}
