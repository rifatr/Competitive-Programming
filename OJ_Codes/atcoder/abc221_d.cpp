// Problem: D - Online games
// Contest: AtCoder - AtCoder Beginner Contest 221
// Time: 2021-10-03 22:05:45
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_d

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
	
	ll ans[n + 1] = {0};
	map <ll, ll> cnt;
	
	lop(n) {
		int l, r;
		cin >> l >> r;
		cnt[l]++;
		cnt[l + r]--;
	}
	ddbg(cnt)
	
	auto it = cnt.begin(), it2 = it++;
	while(it != cnt.end()) {
		it -> ss += it2 -> ss;
		it++;
		it2++;
	}
	ddbg(cnt)
	
	it = cnt.begin(), it2 = it++;
	while(it != cnt.end()) {
		ans[it2 -> ss] += (it -> ff) - (it2 -> ff);
		dbg2(*it, *it2)
		it++;
		it2++;
		ddbg(ans)
	}
	
	print(ans + 1, n);

	return 0;
}
