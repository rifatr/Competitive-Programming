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

const int N = 505, inf = 1e8;
int n, m, dis[N][2];
vector <pii> g[N];

void dijkstra() {
    lop(N) dis[i][0] = dis[i][1] = inf;
    priority_queue <pii> q;
	q.push({0, 0});
	dis[0][0] = 0;
	
	while(!q.empty()) {
	    int u = q.top().ss;
	    q.pop();
	    
	    for(auto v : g[u]) {
	        lop(2) {
	            int d = dis[u][i] + v.ss;
	            if(d < dis[v.ff][1 - i]) {
	                dis[v.ff][1 - i] = d;
	                q.push({-d, v.ff});
	            }
	        }
	    }
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

    int cs = 1;
	while(cin >> n >> m) {
	    lop(m) {
	        int u, v, w;
	        cin >> u >> v >> w;
	        g[u].pb({v, w});
	        g[v].pb({u, w});
	    }
	    
	    dijkstra();
	    cout << "Set #" << cs++ << '\n';
	    dis[n - 1][0] < inf ? print(dis[n - 1][0]) : print('?');
	    
	    lop(n + 3) g[i].clear();	    
	}

	return 0;
}
