// Problem: Forest Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1652
// Time: 2022-02-03 16:12:40

#include <bits/stdc++.h>

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

const int N = 1e3 + 10;
int n, dp[N][N], q;
string grid[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	lop(n) cin >> grid[i];
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j - 1] + (grid[i - 1][j - 1] == '*');
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] += dp[i - 1][j];
		}
	}
	
	while(q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		print(dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1]);
		// print(vin {dp[c][d], dp[a - 1][d], dp[c][b - 1], dp[a - 1][b - 1]});
	}

	return 0;
}