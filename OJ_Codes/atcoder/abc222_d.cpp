// Problem: D - Between Two Arrays
// Contest: AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner Contest 222）
// Time: 2021-10-10 15:05:52
// URL: https://atcoder.jp/contests/abc222/tasks/abc222_d

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

const ll N = 3000 + 9, mod = 998244353;
ll n, a[N], b[N], dp[N][N];

ll rfs(ll p, ll y) {
	if(p == n) return 1;
	if(y > b[p]) return 0;
	if(dp[p][y] != -1) return dp[p][y];
	
	return dp[p][y] = (rfs(p, max(y, a[p]) + 1) + rfs(p + 1, y)) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	lop(n) cin >> a[i];
	lop(n) cin >> b[i];
	
	memset(dp, -1, sizeof dp);
	print(rfs(0, a[0]));

	return 0;
}