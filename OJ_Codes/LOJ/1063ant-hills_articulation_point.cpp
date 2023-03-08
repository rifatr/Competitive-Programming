// Time: 2022-06-23 16:59:23	Problem: Ant Hills 
// URL: https://lightoj.com/problem/ant-hills

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
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const int N = 1e4 + 10;
int n, m, root, Time, low[N], d[N];
bool vis[N], is_arti[N]; // is articulation point
vector <int> g[N];

void dfs(int p, int u) {
    Time++;
    vis[u] = 1;
    d[u] = low[u] = Time;
    
    int child = 0;
    for(int v : g[u]) {
        if(v == p) continue;
        
        if(vis[v]) low[u] = min(low[u], d[v]);
        else {
            child++;
            dfs(u, v);
            
            low[u] = min(low[u], low[v]);
            if(low[v] >= d[u] and u != root) is_arti[u] = 1;    
        }
    }
    
    if(u == root and child > 1) is_arti[u] = 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		cin >> n >> m;
		lop(m) {
		    int u, v; cin >> u >> v;
		    g[u].pb(v);
		    g[v].pb(u);
		}
		
		Time = root = 1;
		memset(vis, 0, sizeof vis);
		memset(is_arti, 0, sizeof is_arti);
		dfs(root, root);
		
		// print(d + 1, n); print(low + 1, n); print(is_arti + 1, n);
		
		Case(cs++);
		print(count(is_arti, is_arti + N, 1));
		lop(n + 1) g[i].clear();
	}

	return 0;
}

/*
case 
1

10 11
3 1
4 1
7 3
10 2
9 5
10 5
8 5
6 10
7 4
7 8
7 2
*/