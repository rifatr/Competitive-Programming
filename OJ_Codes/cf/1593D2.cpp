// Problem: D2. Half of Same
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// Time: 2021-10-15 13:12:15
// URL: https://codeforces.com/contest/1593/problem/D2

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
		int a[n];
		lop(n) cin >> a[i];
		sort(a, a + n);
		
		int ans = 0;
		lop(n / 2 + 1) {
			vin tm;
			for(int j = i; j < n; j++) {
				tm.pb(a[j] - a[i]);
			}
			
			if(count(all(tm), 0) >= n / 2) {
				ans = -1;
				break;
			}
			
			unordered_set <int> dv;
			for(int z : tm) {
				for(int k = 1; k * k <= z; k++) {
					if(z % k == 0) {
						dv.insert(k);
						dv.insert(z / k);
					}
				}
			}
			
			for(int x : dv) {
				int p = 0;
				for(int y : tm) {
					if(y % x == 0) p++;
				}
				if(p >= n / 2) ans = max(ans, x);
			}
		}
		
		print(ans);
	}

	return 0;
}
