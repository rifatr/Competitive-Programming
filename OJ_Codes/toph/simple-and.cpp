// Time: 2022-06-14 02:38:45	Problem: Simple And 
// URL: https://toph.co/p/simple-and

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
// sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll N = 1e5 + 10, inf = (1LL << 31) - 1;
ll n, q, root, val[N], AND[N], dis[N], maxDis;
vin g[N];
bool vis[N];

void bfs() {
    queue <int> q;
    q.push(root);
    memset(vis, 0, sizeof vis);
    vis[root] = 1;
    dis[root] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u, ll k) {
    if(vis[u]) return;
    vis[u] = 1;
    AND[k] &= val[u];
    for(int v : g[u]) dfs(v, k + 1);
    maxDis = max(maxDis, k);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		cin >> n >> q >> root;
		root--;
		lop(n) {
		    cin >> val[i];
		    AND[i] = inf;
		}
		lop(n - 1) {
		    int u, v; cin >> u >> v;
		    u--; v--;
		    g[u].pb(v);
		    g[v].pb(u);
		}
		
		bfs();
		memset(vis, 0, sizeof vis);
		maxDis = 0;
		dfs(root, 0);
		
		while(q--) {
		    int u, k; cin >> u >> k;
		    u--;
		    
		    k += dis[u];
		    if(k > maxDis) print(-1);
		    else print(AND[k]);
		}
	}

	return 0;
}
