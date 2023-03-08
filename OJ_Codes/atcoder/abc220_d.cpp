// Problem: D - FG operation
// Contest: AtCoder - AtCoder Beginner Contest 220
// Time: 2021-09-26 18:31:04
// URL: https://atcoder.jp/contests/abc220/tasks/abc220_d

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
const ll N = 1e5 + 10, mod = 998244353;
ll n, a[N], dp[N][10], k;

ll rfs(int p, int x) {
	if(p == n) return x == k;
	ll &ret = dp[p][x];
	if(ret != -1) return ret;
	
	ret = rfs(p + 1, (x + a[p]) % 10) % mod;
	ret += rfs(p + 1, (x * a[p]) % 10) % mod;
	ret %= mod;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	lop(n) cin >> a[i];
	
	lop(10) {
		memset(dp, -1, sizeof dp);
		k = i;
		print(rfs(1, a[0]));
	}	

	return 0;
}
