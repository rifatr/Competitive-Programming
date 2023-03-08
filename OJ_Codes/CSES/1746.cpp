// Problem: Array Description
// Contest: CSES - CSES Problem Set
// Time: 2021-08-18 15:55:50
// URL: https://cses.fi/problemset/task/1746/


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

const ll N = 1e5 + 30, M = 103, mod = 1e9 + 7;
ll n, m, a[N], dp[M][N];

ll rfs(int pre, int i) {
	if(i == n) return 1;
	ll &x = dp[pre][i];
	if(x != -1) return x;
	
	if(a[i] and a[i + 1] and abs(a[i] - a[i + 1]) > 1) return 0;
	
	if(a[i]) return x = rfs(a[i], i + 1);
	
	x = 0;
	if(!i) {
		ll p = 1, q = a[i + 1] ? a[i + 1] + 1 : min(m, 100ll);
		while(p <= q) {
			x += rfs(p, i + 1);
			x %= mod;
			p++;
		}
		return x;
	}
	
	if(!a[i + 1]) {
		ll p = max(1, pre - 1), q = min(m, (ll) pre + 1);
		while(p <= q) {
			x += rfs(p, i + 1);
			x %= mod;
			p++;
		}
		return x;
	}
	
	ll p = max(pre - 1, 1), q = min(m, a[i + 1] + 1);
	if(p > q) swap(p, q);
	while(p <= q) {
		if(abs(pre - p) <= 1 and abs(a[i + 1] - p) <= 1) {
			x += rfs(p, i + 1);
			x %= mod;
		}
		p++;
	}
	
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	lop(n) cin >> a[i];
	
	memset(dp, -1, sizeof dp);
	print(rfs(0, 0));
	
	return 0;
}