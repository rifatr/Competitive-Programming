// Problem: D - Strange Lunchbox
// Contest: AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest 219）
// Time: 2021-09-18 19:57:47
// URL: https://atcoder.jp/contests/abc219/tasks/abc219_d

#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifndef ONLINE_JUDGE
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

const int N = 306, inf = 1 << 30;
int n, x, y, a[N], b[N], dp[N][N][N];

int rfs(int i, int p, int q) {
	if(p >= x and q >= y) return 0;
	if(i >= n) return inf;
	int &ret = dp[i][p][q];
	if(ret != -1) return ret;
	
	ret = min(rfs(i + 1, p, q), 1 + rfs(i + 1, min(x, p + a[i]), min(y, q + b[i])));
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> x >> y;
	lop(n) cin >> a[i] >> b[i];
	
	memset(dp, -1, sizeof dp);
	print(rfs(0, 0, 0) < inf ? rfs(0, 0, 0) : -1);

	return 0;
}
