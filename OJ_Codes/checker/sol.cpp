// Time: 2022-08-19 17:43:52	Problem: A - Ricky Rick
// URL: https://vjudge.net/contest/511234#problem/A

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
// sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll N = 1e5 + 10;
ll n, qq, par[N], cy[N], t[N], dis[N];
set <pii> st;

int fr(int x) {
	return par[x] = par[x] == x ? x : fr(par[x]);
}
void Uni(int u, int v) {
	if (v < u) swap(u, v);
	if (st.count({u, v})) return;
	st.insert({u, v});

	int x = fr(u), y = fr(v);
	if (y == x) cy[y] = 1;
	else {
		par[x] = y;
		cy[y] |= cy[x];
		cy[x] |= cy[y];
	}

	if (dis[v] != -1) dis[u] = 1 - dis[v];
	else if (dis[u] != -1) dis[v] = 1 - dis[u];
	else dis[v] = 1, dis[u] = 0;
	// dbg2(u, v) dbg2(x, y) print(dis + 1, n);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> qq;
	lop(n) cin >> t[i + 1], par[i + 1] = i + 1;
	memset(dis, -1, sizeof dis);

	while (qq--) {
		int op; cin >> op;
		if (op == 1) {
			int x, y; cin >> x >> y;
			t[x] = y;
		}
		else if (op == 2) {
			int x, y; cin >> x >> y;
			Uni(x, y);
		}
		else {
			int u, v, z; cin >> u >> v >> z;

			int x = fr(u), y = fr(v);
			// fr(x), fr(y);
			if (x != y or cy[x]) {
				print(0);
				continue;
			}

			ll p = t[u] * z, q = t[v];
			ll b = __gcd(p, q);
			while (b != 1) {
				p /= b;
				q /= b;
				b = __gcd(p, q);
			}

			p *= (dis[u] == dis[v] ? 1 : -1);
			// dbg2(u, v) dbg2(p, q) dbg2(dis[u], dis[v])
			cout << p << "/" << q << '\n';
		}
	}

	return 0;
}
