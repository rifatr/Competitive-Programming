// Time: 2022-06-13 15:24:37	Problem: Country Roads 
// URL: https://lightoj.com/problem/country-roads

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ":\n"

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)
#define loop(i, a, b) for (int i = a; i < b; i++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifdef rifat
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

struct Edge {
    int v, w;
    
    bool operator < (const Edge &b) const {
        return w > b.w;
    }
};

const int N = 505, inf = 1e9;
int n, m, t, dis[N], W[N][N];
vector <Edge> g[N];

void dijkstra() {
    fill(dis, dis + n, inf);
    dis[t] = 0;
    priority_queue <Edge> q;
    q.push({t, -1});
    
    while(!q.empty()) {
        int u = q.top().v;
        q.pop();
                
        for(auto vv : g[u]) {
            if(max(dis[u], vv.w) < dis[vv.v]) {
                dis[vv.v] = max(dis[u], vv.w);
                q.push({vv.v, dis[vv.v]});
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		cin >> n >> m;
		lop(n) lopj(n) W[i][j] = inf;
		lop(m) {
		    int u, v, w; cin >> u >> v >> w;
		    W[u][v] = min(W[u][v], w);
		    W[v][u] = W[u][v];
		}
		lop(n) lopj(n) {
		    if(W[i][j] < inf) {
		        g[i].pb({j, W[i][j]});
		    }
		}
		cin >> t;

		dijkstra();
		Case(cs++);
		lop(n) {
		    if(dis[i] >= inf) print("Impossible");
		    else print(dis[i]);
		    
		    g[i].clear();
		}
	}

	return 0;
}
