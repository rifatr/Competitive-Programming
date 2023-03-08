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

const int N = 2e5 + 20;
int n, deg[N], par[N], root;
bool vis[N];

void dfs(int u, vin &b) {
	if (vis[u]) return;
	vis[u] = 1;
	b.pb(u);
	dfs(par[u], b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		cin >> n;
		lop(n + 3) vis[i] = deg[i] = 0;
		loop(i, 1, n + 1) cin >> par[i];
		loop(i, 1, n + 1) {
			if (par[i] == i) root = i;
			else deg[par[i]]++;
		}

		vector <vin> ans;
		loop(i, 1, n + 1) {
			if (deg[i] == 0) {
				vin vv;
				dfs(i, vv);
				reverse(all(vv));
				ans.pb(vv);
			}
		}

		print(ans.size());
		for (auto &z : ans) {
			print(z.size());
			print(z);
		}
		print("");
	}

	return 0;
}
