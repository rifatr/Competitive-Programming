// Time: 2022-06-27 17:32:48	Problem: Critical Links 
// URL: https://lightoj.com/problem/critical-links

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

const int N = 1e4 + 10;
int n, m, root, Time, low[N], d[N];
bool vis[N];
vector <int> g[N];
vector <pii> arti_bridge;

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
           if(d[u] < low[v]) {
               arti_bridge.pb({min(u, v), max(u, v)});
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
		cin >> n;
		for(int i = 0; i < n; i++) {
		    int u; cin >> u;
		    string s; cin >> s; s.pop_back(); s.erase(s.begin());
		    int k = stoi(s);
		    
		    for(int j = 0; j < k; j++) {
		        int v; cin >> v;
		        g[u].pb(v);
		        // g[v].pb(u);
		    }
		}
		
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; i++) {
		    if(vis[i]) continue;
		    Time = root = i;
		    dfs(root, root);
		}
		
		sort(all(arti_bridge));
		
		Case(cs++);
		cout << arti_bridge.size() << " critical links\n";
		for(auto z : arti_bridge) {
		    cout << z.ff << " - " << z.ss << '\n';
		}
		
		arti_bridge.clear();
		lop(n + 1) g[i].clear();
	}

	return 0;
}
