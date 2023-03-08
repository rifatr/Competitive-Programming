struct edge {
	int u, v, w;
	bool operator < (const edge &b) const {
		return w > b.w;
	}
};

const int N = 2e5;
int n, m, par[N];
vector <edge> eg;

int findpar(int x) {
	return par[x] = par[x] == x ? x : findpar(par[x]);
}

void Union(int u, int v) {
	par[findpar(u)] = findpar(v);
}

int kruskal() {
	sort(eg.begin(), eg.end());
	iota(par, par + n, 0);

	int cost = 0, connected = 0;
	while (connected != n - 1) {
		edge z = eg.back();
		eg.pop_back();

		int x = findpar(z.u), y = findpar(z.v);
		if (x != y) {
			connected++;
			cost += z.w;
			Union(x, y);
		}
	}

	return cost;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		eg.push_back({u, v, w});
	}

	cout << kruskal() << '\n';

	return 0;
}