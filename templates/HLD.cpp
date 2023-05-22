// Time: 2023-03-22 19:58:50 Problem: C - Query on a tree II
// URL: https://vjudge.net/contest/548789#problem/C

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
int n, tim;
int a[N], b[N], c[N], subtree[N], par[N], head[N], in[N],  out[N];
int tr[4 * N]; // segment tree
vector <pii> g[N];

void dfs_subtree(int p, int u) {
	subtree[u] = 1;
	par[u] = p;

	for (auto &x : g[u]) {
		int v = x.ff, w = x.ss;
		if (v == p) continue;

		dfs_subtree(u, v);
		subtree[u] += subtree[v];
		b[v] = w; // assigning cost of u-v at node v

		if (subtree[g[u][0].ff] <= subtree[v])
			swap(g[u][0], x);
	}
}

void dfs_HLD(int p, int u) {
	if (p == -1) head[u] = u;

	in[u] = ++tim;
	c[tim] = u;
	for (auto &x : g[u]) {
		int v = x.ff, w = x.ss;
		if (v == p) continue;

		head[v] = (v == g[u][0].ff ? head[u] : v);
		dfs_HLD(u, v);
	}

	out[u] = tim;
}

// basic segment tree starts
void build(int lo, int hi, int node)
{
	if (lo == hi) {
		tr[node] = a[lo];
		return;
	}
	int mid = (lo + hi) >> 1, lft = node << 1, rgt = lft | 1;
	build(lo, mid, lft);
	build(mid + 1, hi, rgt);
	tr[node] = tr[lft] + tr[rgt];
}

void update(int lo, int hi, int idx, int v, int node)
{
	if (lo > idx || hi < idx) return;
	if (lo == hi) {
		tr[node] = v;
		return;
	}
	int mid = (lo + hi) >> 1, lft = node << 1, rgt = lft | 1;
	update(lo, mid, idx, v, lft);
	update(mid + 1, hi, idx, v, rgt);
	tr[node] = tr[lft] + tr[rgt];
}

int query(int lo, int hi, int l, int r, int node)
{
	if (lo > r || hi < l) return 0;
	if (lo >= l && hi <= r) return tr[node];
	int mid = (lo + hi) >> 1, lft = node << 1, rgt = lft | 1;
	return query(lo, mid, l, r, lft) + query(mid + 1, hi, l, r, rgt);
}
// basic segment tree ends

inline void update(int u, int x) {
	update(1, tim, in[u], x, 1);
}
inline int query(int l, int r) {
	return query(1, tim, in[l], in[r], 1);
}
inline bool isAnchestor(int u, int v) { // is u a anchestor of v?
	return in[u] <= in[v] and out[u] >= out[v];
}

int query_tree(int u, int v) {
	int res = 0;
	while (!isAnchestor(head[u], v)) {
		int x = query(head[u], u);
		res += x;
		u = par[head[u]];
	}
	swap(u, v);
	while (!isAnchestor(head[u], v)) {
		int x = query(head[u], u);
		res += x;
		u = par[head[u]];
	}

	if (in[v] < in[u]) swap(u, v); // U is LCA.
	res += query(u, v) - query(u, u); // Cost of u (which belongs to [par[u], u]) is not part of this path
	return res;
}

pii query_length(int u, int v) {
	int l = 0;
	while (!isAnchestor(head[u], v)) {
		l += in[u] - in[head[u]] + 1;
		u = par[head[u]];
	}
	swap(u, v);
	while (!isAnchestor(head[u], v)) {
		l += in[u] - in[head[u]] + 1;
		u = par[head[u]];
	}

	if (in[v] < in[u]) swap(u, v);
	l += in[v] - in[u] + 1;
	return {l, u}; // u is LCA
}

int up(int u, int k) {
	if (k <= 0) return u;
	while (1) {
		if (in[u] - in[head[u]] + 1 >= k) break;
		k -= in[u] - in[head[u]] + 1;
		u = par[head[u]];
	}

	int d = query_length(head[u], u).ff - k;
	return c[in[head[u]] + d];
}

void clr() {
	lop(n + 5) g[i].clear();
	tim = 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		cin >> n;
		clr();

		for (int i = 0; i < n - 1; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}

		dfs_subtree(-1, 1); // 1 is root
		dfs_HLD(-1, 1);
		for (int i = 1; i <= n; i++)
			a[in[i]] = b[i];
		build(1, tim, 1);

		string s; int l, r, k;
		while (1) {
			cin >> s;
			if (s == "DONE") break;
			cin >> l >> r;

			if (s == "DIST") {
				print(query_tree(l, r));
			}
			else {
				cin >> k;

				auto x = query_length(l, r);
				int lft = query_length(l, x.ss).ff, rht = query_length(x.ss, r).ff;
				print(lft >= k ? up(l, k) : up(r, lft + rht - k));
			}
		}
		print("");
	}

	return 0;
}
