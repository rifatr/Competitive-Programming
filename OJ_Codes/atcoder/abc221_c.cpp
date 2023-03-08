// Problem: C - Select Mul
// Contest: AtCoder - AtCoder Beginner Contest 221
// Time: 2021-10-03 21:31:59
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_c

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

	string s;
	cin >> s;
	sort(all(s));
	if(s.size() == 1) {
		print(s);
		return 0;
	} 
	
	ll ans = 0;
	do {
		if(s[0] == '0') continue;
		ll x = s[0] - '0', y;
		for(int i = 1; i < s.size(); i++) {
			if(s[i] == '0') {
				x *= 10;
				continue;
			}
			y = 0;
			for(int j = i; j < s.size(); j++) {
				y *= 10;
				y += s[j] - '0';
			}
			ans = max(ans, x * y);
			x *= 10;
			x += s[i] - '0';
		}
		
	} while(next_permutation(all(s)));
	
	print(ans);

	return 0;
}
