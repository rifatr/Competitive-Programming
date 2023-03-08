// Time: 2023-01-17 22:08:02	Problem: G. Polymorphism 
// URL: https://algo.codemarshal.org/contests/ruet-2022/problems/G

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "yes\n"
#define no cout << "no\n"
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

struct qu {
    int op, u, v;
};

const int N = 1e5 + 20, M = 17;
unordered_map <string, int> mp;
qu q[N];
vector <int> g[N];
int n, d[N], anc[N], root, spt[M][N];

void dfs(int nd,int pa=-1,int c=0){
for(int j=0,ch;j<g[nd].size();++j){
ch=g[nd][j] ;
if(ch==pa)continue ;
dfs(ch,nd,c+1) ;
}
}
int lca(int u,int v){
if(d[u]<d[v])swap(u,v) ;
for(int j=19;j>=0 and d[u]>d[v];--j){ /// u niche ...
if(d[anc[u][j]]>=d[v])
u=anc[u][j] ;
}
for(int j=19;j>=0 and u!=v;--j){
if(anc[u][j]!=anc[v][j])
u=anc[u][j] , v=anc[v][j] ;
u=anc[u][0] , v=anc[v][0] ;
}
return u ;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		Case(cs++);
		
		cin >> n;
		int k = 1;
		mp["Main"] = k++;
		lop(n) {
		    string a, b, c, d;
		    cin >> a;
		    if(a == "+") { //+ class Abc extends Main
		        cin >> d >> b >> d >> c;
		        mp[b] = k++;
		        q[i] = {0, mp[c], mp[b]};
		        
		        g[mp[c]].pb(mp[b]);
		    }
		    else { // ? Abc obj = new Abc()
		        cin >> b >> d >> d >> d >> c;
		        c.pop_back();
		        c.pop_back();
		        if(!mp[b]) mp[b] = k++;
		        if(!mp[c]) mp[c] = k++;
		        q[i] = {1, mp[b], mp[c]};
		    }
		}
		
		root = 1;
		dfs(-1, root, 0);
    	// lca_build();
		
		set <int> ache;
		ache.insert(1);
		lop(n) {
		    if(!q[i].op) ache.insert(q[i].v);
		    else {
		        if(ache.count(q[i].u) and ache.count(q[i].v) and lca_of(q[i].u, q[i].v) == q[i].u) yes;
		        else no;
		    }
		}
		
		lop(n + 1) g[i].clear();
		mp.clear();
	}

	return 0;
}
