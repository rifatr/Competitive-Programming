// Problem: C1: Gold Mine - Chapter 1
// Contest: Facebook Coding Competitions - Facebook Hacker Cup 2021 Qualification Round
// Time: 2021-08-29 00:15:45
// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/C1


#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case #" << int(i) << ": "

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

const int N = 54;
ll n, a[N], b[N], ans;
vll g[N];
bool vis[N];

// void dfs(int u, int v) {
	// vis[v] = 1;
	// b[v] = a[v] + b[u];
	// for(int z : g[v]) {
		// if(!vis[z]) {
			// dfs(v, z);
		// }
	// }
// }

void dfs(int u, int v, ll s) {
	if(vis[v]) {
		if(v == 1) ans = max(ans, s);
		return;
	}
	vis[v] = 1;
	for(int z : g[v]) {
		if(z != u) dfs(v, z, s + a[v]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int tc, t = 1;
	cin >> tc;
	
	while (tc--)
	{
		Case(t++);
		
		cin >> n;
		lop(n) cin >> a[i + 1];
		lop(n - 1) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		ans = -1;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				bool f = 1;
				for(int z : g[j]) if(z == i) f = 0;
				if(!f) continue;
				
				memset(vis, 0, sizeof vis);
				
				g[i].pb(j);
				g[j].pb(i);
				dfs(0, 1, 0);
				g[i].pop_back();
				g[j].pop_back();
			}
		}
		
		if(ans == -1) {
			ans = 0;
			lop(n) ans += a[i + 1];
		}
		print(ans);
		
		// memset(vis, 0, sizeof vis);
		// memset(b, 0, sizeof b);
		// dfs(0, 1);
		// vll v;
		// lop(n + 1) {
			// if(g[i].size() == 1) v.pb(b[i]);
		// }
		// v.pb(0), v.pb(0);
		// sortd(v);
		// ddbg(v)
		// Case(t++);
		// print(v[0] + v[1] - a[1]);
		lop(n + 1) g[i].clear();
	}
	
	return 0;
}