#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int n, m, root, Time, low[N], d[N];
bool vis[N], is_arti[N]; // is articulation point
vector <int> g[N];
vector <pair <int, int>> arti_bridge;

void dfs(int p, int u) {
	Time++;
	vis[u] = 1;
	d[u] = low[u] = Time;

	int child = 0;
	for (int v : g[u]) {
		if (v == p) continue;

		if (vis[v]) low[u] = min(low[u], d[v]);
		else {
			child++;
			dfs(u, v);

			low[u] = min(low[u], low[v]);
			if (low[v] >= d[u] and u != root)
				is_arti[u] = 1;

			if (d[u] < low[v])
				arti_bridge.push_back({min(u, v), max(u, v)});
		}
	}

	if (u == root and child > 1)
		is_arti[u] = 1;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	Time = root = 1;
	memset(vis, 0, sizeof vis);
	memset(is_arti, 0, sizeof is_arti);
	dfs(root, root);
}