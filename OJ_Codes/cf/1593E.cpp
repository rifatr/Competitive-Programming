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

const int N = 4e5 + 10;
int n, deg[N], k;
vin g[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		cin >> n >> k;
		lop(n + 3) {
			g[i].clear();
			deg[i] = 0;
		}
		lop(n - 1) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
			deg[u]++;
			deg[v]++;
		}
		
		vin lf;
		for(int i = 1; i <= n; i++) {
			if(deg[i] <= 1) {
				lf.pb(i);
				deg[i]--;
			}
		}
		int rmv = lf.size();
		
		while(--k > 0 and rmv < n) {
			vin tm;
			for(int u : lf) {
				for(int v : g[u]) {
					if(deg[v]) {
						deg[v]--;
						if(deg[v] == 1) tm.pb(v);
					}
				}
			}
			lf = tm;
			rmv += tm.size();
		}
		
		print(n - rmv);
	}

	return 0;
}
