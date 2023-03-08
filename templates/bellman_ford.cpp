//bellman ford with negative cycle print
struct edge {
  ll v, w;
};
const ll N = 3e3 + 6, inf = 1LL << 60;
ll n, m, dis[N], par[N];
vector<edge> g[N];

int bellman_ford() {
  lop(n + 1) dis[i] = inf;
  dis[1] = 0;
  int cy;

  lop(n + 1) {
    cy = -1;
    for (int u = 1; u <= n; u++) {
      for (auto z : g[u]) {
        ll v = z.v, w = z.w;
        if (dis[u] + w < dis[v]) {
          dis[v] = dis[u] + w;
          par[v] = u;
          cy = v; // if(u == n) negative cycle;
        }
      }
    }
  }
  return cy; //cy is a adjacent node or a node of negative cycle
}

int main() {
  cin >> n >> m;
  lop(m) {
    ll u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
  }

  int x = bellman_ford();
  if (x == -1) {
    //no negative cycle
    return 0;
  }

//x can be not a part of cycle, so if we go through //path sometimes, x will be a node of cycle
  lop(n) x = par[x];
  vector<int> cycle;
  int i = x;
  while (i != x or cycle.size() <= 1) {
    cycle.pb(i);//retrieving cycle
    i = par[i];
  }
  cycle.pb(i);
  reverse(all(cycle));
  for (int z : cycle)
    cout << z << ' ';
  return 0;
}
