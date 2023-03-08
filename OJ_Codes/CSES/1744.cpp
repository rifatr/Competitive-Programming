// Problem: Rectangle Cutting
// Contest: CSES - CSES Problem Set
// Time: 2021-08-18 19:27:52
// URL: https://cses.fi/problemset/task/1744


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
#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "\t", dbg(y);
#define dbg3(x, y, z) cout << #x << " = " << x << "\t", dbg2(y, z);
#define ddbg(x) cout << #x << " = [ "; for(auto z : x) cout << z << ' '; cout << "]\n";
#else
#define dbg(x)
#define adbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#define ddbg(x)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for(int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ':'\n');}

using namespace std;

const ll N = 505, inf = 1e9;
ll dp[N][N];

ll rfs(int w, int h) {
	if(w == h) return 0;
	ll &x = dp[w][h];
	if(x != -1) return x;
	
	x = inf;
	for(int i = 1; i < h; i++) {
		x = min(x, 1 + rfs(w, h - i) + rfs(w, i));
	}
	for(int i = 1; i < w; i++) {
		x = min(x, 1 + rfs(w - i, h) + rfs(w, h));
	}
	
	dbg3(w, h, x)
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int w, h;
	cin >> w >> h;
	
	memset(dp, -1, sizeof dp);	
	print(rfs(w, h));
	
	return 0;
}