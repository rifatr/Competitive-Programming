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

struct Node {
	ll v, w;
};
struct EDGE {
	ll u, v, w, contri;
	
	bool operator < (const EDGE &b) const {
		return contri > b.contri;
	}
};

const int N = 2e4 + 200;
ll n, subtree[N];
bool vis[N];
EDGE edg[N];
vector <Node> g[N];

void dfs(int v) {	
	vis[v] = 1;
	for(auto z : g[v]) {
		if(vis[z.v]) continue;
		
		dfs(z.v);
		subtree[v] += subtree[z.v];
	}
	
	subtree[v]++;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for(int tt = 1; tt <= tc; tt++)
	{		
		cin >> n;
		lop(n - 1) {
			ll u, v, w;
			cin >> u >> v >> w;
			
			g[u].pb({v, w});
			g[v].pb({u, w});

			edg[i] = {u, v, w, 0};
		}
		
		//subtree calculation
		dfs(1);
		//beatuness calculation
		ll s = 0;
		lop(n - 1) {
			ll b = subtree[edg[i].v];
			
			edg[i].contri = (n - b) * b;
			s += edg[i].contri * edg[i].w;
		}
		
		//beautiness edition
		sort(edg, edg + n - 1);
		ll res = 0;
		lop(n - 1) {
			if(s >= 0) break;
			if(edg[i].w >= 0) continue;
			
			ll x = ceil((double) -s / edg[i].contri);
			ll y = min(x, -edg[i].w);
			
			s += edg[i].contri * y;
			res += y;
		}
		
		Case(tt);
		print(res);
		
		lop(n + 5) {
			g[i].clear();
			subtree[i] = vis[i] = 0;
		}
	}
	
	return 0;
}
