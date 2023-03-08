#include <bits/stdc++.h>
using namespace std;

const int N = 2e5, M = 20;
int n, level[N], par[N], root, spt[M][N];
vector <int> g[N];

void dfs(int u, int v, int c) {
    par[v] = u;
    level[v] = c;
    
    for(int &z : g[v]) if(z != u) dfs(v, z, c + 1);
}

void lca_build() {
    memset(spt, -1, sizeof spt);
    
    for(int i = 1; i <= n; i++) spt[0][i] = par[i];
    for(int i = 1; i < M; i++) {
        for(int j = 1; j <= n; j++) {
            int p = spt[i - 1][j];
            if(p >= root) spt[i][j] = spt[i - 1][p]; // 2^i-th parent of j
        }
    }
}

int lca_of(int u, int v) {
    int p = u, q = v; 
    if(level[p] > level[q]) swap(p, q);  // lets level[p] <= level[q]
    int d = level[q] - level[p];
    for(int i = M - 1; i >= 0 and d; i--) {
        if(d >= (1 << i)) {
            d -= 1 << i;
            q  = spt[i][q];
        }
    }
    // now level[p] = level[q]
    if(p == q) return p;
    
    for(int i = M - 1; i >= 0; i--) {
        if(spt[i][p] >= root and spt[i][p] != spt[i][q]) {
            p = spt[i][p];
            q = spt[i][q];
        }
    }
    return spt[0][p];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    
    root = 1;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
	    int u, v;
	    cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	
	dfs(-1, root, 0);
	lca_build();
	
	/*for(int i = 0; i < n; i++) cout << i << ' ' << par[i] << endl;
	for(int i = 0; i < 4; i++) {
	    cout << "parent level = " << (1 << i) << endl;
	    for(int j = 0; j < n; j++)
	        cout << j << ' ' << spt[i][j] << endl;
	}*/
	
	int q; cin >> q;
	while(q--) {
	    int u, v;
	    cin >> u >> v;
	    cout << lca_of(u, v) << '\n';
	}
	
	return 0;
}
