#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << #a << ": " << a << "\n"

using ll = long long;

struct DSU {
	vector<int> par, col;
	vector<vector<int>> comps;
	DSU(int n): par(n), col(n), comps(n) {
		iota(par.begin(), par.end(), 0);
		for (int u = 0; u < n; ++u) {
			comps[u] = {u};
		}
	}

	int find(int v) {
		return (par[v] == v) ? v : par[v] = find(par[v]);
	}

	void unite(int u, int v) {
		int r_u = find(u);
		int r_v = find(v);
		if (comps[r_u].size() < comps[r_v].size()) {
			swap(u, v);
			swap(r_u, r_v);
		}

		if (col[v] == col[u]) {
			for (auto &w : comps[r_v]) {
				col[w] ^= 1;
			}
		}
		comps[r_u].insert(comps[r_u].end(), comps[r_v].begin(), comps[r_v].end());
		comps[r_v].clear();
		par[r_v] = r_u;
	}

	bool same_set(int u, int v) {
		return find(u) == find(v);
	}
};


void solve() {
	int n, m;  cin >> n >> m;
	vector<ll> a(n);
	for (auto &ai : a) {
		cin >> ai;
	}

	DSU dsu(n);
	vector<int> blocked(n);

	while (m--) {
		int tp;  cin >> tp;
		if (tp == 1) {
			int x, c;  cin >> x >> c;  x--;
			a[x] = c;
		}
		else if (tp == 2) {
			int x, y;  cin >> x >> y;  x--, y--;
			int r_x = dsu.find(x);
			int r_y = dsu.find(y);
			if (r_x == r_y) {
				if (dsu.col[x] == dsu.col[y]) {
					blocked[r_x] = 1;
				}
			}
			else {
				if (blocked[r_x] or blocked[r_y]) {
					blocked[r_x] = blocked[r_y] = 1;
				}
				else {
					dsu.unite(x,  y);
				}
			}
		}
		else {
			int x, y, v;  cin >> x >> y >> v;  x--, y--;
			if (!dsu.same_set(x, y) or blocked[dsu.find(x)]) {
				cout << "0\n";
			}
			else {
				if (dsu.col[x] != dsu.col[y]) {
					cout << "-";
				}
				ll num = a[x] * v, den = a[y];
				ll g = __gcd(num, den);
				num /= g, den /= g;
				cout << num << "/" << den << "\n";
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int ttc = 1;
	for (int tc = 1; tc <= ttc; ++tc) {
		solve();
	}
}