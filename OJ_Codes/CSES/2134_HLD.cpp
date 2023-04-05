//https://cses.fi/problemset/task/2134
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, q, tim, a[N], b[N], subtree[N], par[N], head[N], in[N],  out[N];
int tr[4 * N]; // segment tree
vector <int> g[N];

inline void dfs_subtree(int p, int u) {
	subtree[u] = 1;
	par[u] = p;

	for (int &v : g[u]) {
		if (v == p) continue;

		dfs_subtree(u, v);
		subtree[u] += subtree[v];

		if (subtree[g[u][0]] < subtree[v])
			swap(g[u][0], v);
	}
}

inline void dfs_HLD(int p, int u) {
	if (p == -1) head[u] = u;

	in[u] = ++tim;
	for (int &v : g[u]) {
		if (v == p) continue;

		head[v] = (v == g[u][0] ? head[u] : v);
		dfs_HLD(u, v);
	}

	out[u] = tim;
}

// basic segment tree starts
inline void build(int lo, int hi, int node)
{
	if (lo == hi) {
		tr[node] = a[lo];
		return;
	}
	int mid = (lo + hi) >> 1, lft = node << 1, rgt = lft | 1;
	build(lo, mid, lft);
	build(mid + 1, hi, rgt);
	tr[node] = max(tr[lft], tr[rgt]);
}

inline void update(int lo, int hi, int idx, int v, int node)
{
	if (lo > idx || hi < idx) return;
	if (lo == hi) {
		tr[node] = v;
		return;
	}
	int mid = (lo + hi) >> 1, lft = node << 1, rgt = lft | 1;
	update(lo, mid, idx, v, lft);
	update(mid + 1, hi, idx, v, rgt);
	tr[node] = max(tr[lft], tr[rgt]);
}

inline int query(int lo, int hi, int l, int r, int node)
{
	if (lo > r || hi < l) return 0;
	if (lo >= l && hi <= r) return tr[node];
	int mid = (lo + hi) >> 1, lft = node << 1, rgt = lft | 1;
	return max(query(lo, mid, l, r, lft), query(mid + 1, hi, l, r, rgt));
}
// basic segment tree ends

inline void upd(int u, int x) {
	update(1, tim, in[u], x, 1);
}
inline int qu(int l, int r) {
	return query(1, tim, in[l], in[r], 1);
}

inline bool isAnchestor(int u, int v) { // is u a anchestor of v?
	return in[u] <= in[v] and out[u] >= out[v];
}

inline int query_tree(int u, int v) {
	int res = 0;
	while (!isAnchestor(head[u], v)) {
		int x = qu(head[u], u);
		res = max(res, x);
		u = par[head[u]];
	}
	swap(u, v);
	while (!isAnchestor(head[u], v)) {
		int x = qu(head[u], u);
		res = max(res, x);
		u = par[head[u]];
	}

	if (in[v] < in[u]) swap(u, v);
	res = max(res, qu(u, v));
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs_subtree(-1, 1); // 1 is root
	dfs_HLD(-1, 1);
	for (int i = 1; i <= n; i++)
		a[in[i]] = b[i];
	build(1, tim, 1);

	while (q--) {
		int op, u, v; cin >> op >> u >> v;
		if (op == 1) upd(u, v);
		else cout << query_tree(u, v) << ' ';
	}
}