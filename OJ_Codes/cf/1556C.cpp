// Problem: C. Compressed Bracket Sequence
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// Time: 2021-09-08 15:59:04
// URL: https://codeforces.com/contest/1556/problem/C

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
	ll a[n];
	lop(n) cin >> a[i];
	
	auto cal = [&] (int l, int r) {
		ll op = 1, s = 1; 
		// s - how many brackets opened without closing, op - how many closed bracket without opening
		for(int i = l + 1; i < r; i++) {
			op += i % 2 ? max(0ll, a[i] - s) : 0;
			s += i % 2 ? -a[i] : a[i];	
			s = max(0ll, s);
			
		}
		
		return s > a[r] or op > a[l] ? 0ll : 1 + min(a[l] - op, a[r] - s);
	};
	
	ll ans = 0;
	for(int i = 0; i < n; i += 2) {
		for(int j = i + 1; j < n; j += 2) {
			ans += cal(i, j);
		}
	}
	
	print(ans);

	return 0;
}
