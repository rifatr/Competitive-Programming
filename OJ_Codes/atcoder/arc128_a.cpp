// Problem: A - Gold and Silver
// Contest: AtCoder - Daiwa Securities Co. Ltd. Programming Contest 2021（AtCoder Regular Contest 128）
// Time: 2021-10-17 01:22:21
// URL: https://atcoder.jp/contests/arc128/tasks/arc128_a

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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	double a[n];
	lop(n) cin >> a[i];
	
	bool ans[n] = {0};
	lop(n - 1) {
	    if(a[i + 1] < a[i]) {
	        ans[i] ^= 1;
	        ans[i + 1] = 1;
	    }
	}
	
	print(ans, n);

	return 0;
}