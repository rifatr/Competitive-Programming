// Problem: B. Swaps
// Contest: Codeforces - Codeforces Round #743 (Div. 2)
// Time: 2021-09-19 07:14:45
// URL: https://codeforces.com/contest/1573/problem/B

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

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		int a[n], b[n];
		lop(n) cin >> a[i];
		lop(n) cin >> b[i];
		
		int pos[2 * n + 2], GE[2 * n + 2] = {0};
		lop(n) {
			pos[a[i]] = pos[b[i]] = i;
		}
		pos[0] = 1e8;
		
		int mx = 0;
		lop(n) {
			if(mx < b[i]) {
				mx = b[i] - 1;
				GE[mx] = b[i];
			}
		}
		for(int i = mx - 1; i > 0; i--) {
			if(!GE[i]) GE[i] = GE[i + 1];
		}
		
		int ans = 1e8;
		for(int i = 1; i < 2 * n; i += 2) {
			ans = min(ans, pos[i] + pos[GE[i]]);
		} 
		
		print(ans);
	}

	return 0;
}
