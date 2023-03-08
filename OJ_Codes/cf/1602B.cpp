// Problem: B. Divine Array
// Contest: Codeforces - Codeforces Round #751 (Div. 2)
// Time: 2021-10-26 03:57:49
// URL: https://codeforces.com/contest/1602/problem/B

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
		vin a(n), b(n);
		lop(n) cin >> a[i];
		
		vector <vin> ab;
		ab.pb(a);
		int p = 0;
		while(1) {
    	    lop(n) {
    	        int c = 0;
    	        lopj(n) c += ab[p][i] == ab[p][j];
    	        b[i] = c;
    	    }
    	    if(b == ab.back()) break;
    	    ab.pb(b);
    	    p++;
		}
		
		int q;
		cin >> q;
		while(q--) {
		    int x, k;
		    cin >> x >> k;
		    print(ab[min(k, p)][x - 1]);
		}
	}

	return 0;
}
