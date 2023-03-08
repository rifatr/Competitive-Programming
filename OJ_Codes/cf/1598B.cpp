// Problem: B. Groups
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// Time: 2021-10-15 16:18:46
// URL: https://codeforces.com/contest/1598/problem/B

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

void solve() {
    int n;
	cin >> n;
	int d[n][5], taken[n];
	lop(n) lopj(5) cin >> d[i][j];
	
	lop(5) {
	    lopj(5) {
	        if(i == j) continue;
	        int x = 0, y = 0;
	        memset(taken, 0, sizeof taken);
	        for(int k = 0; k < n; k++) {
	            if(x == n / 2) break;
	            if(d[k][i] and !d[k][j]) {
	                taken[k] = 1;
	                x++;
	            }
	        }
	        for(int k = 0; k < n; k++) {
	            if(x == n / 2) break;
	            if(d[k][i] and !taken[k]) {
	                taken[k] = 1;
	                x++;
	            }
	        }
	        for(int k = 0; k < n; k++) {
	            if(y == n / 2) break;
	            if(d[k][j] and !taken[k]) {
	                y++;
	            }
	        }
	        
	        if(x == y and x == n / 2) {
	            yes;
	            return;
	        }
	    }
	}
	
	no;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		solve();
	}

	return 0;
}
