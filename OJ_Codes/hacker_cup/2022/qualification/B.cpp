#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "Possible\n"
#define no cout << "Impossible\n"
#define Case(i) cout << "Case #" << int(i) << ": "

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

const int N = 3e3 + 10;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int n, m;
char s[N][N];
bool vis[N][N];

inline bool is_inside(int x, int y) {
	return min(x, y) >= 0 and x < n and y < m;
}
inline int count_tree(int x, int y) {
	int c = 0;
	lop(4) {
		c += is_inside(x + dr[i], y + dc[i]) and s[x + dr[i]][y + dc[i]] == '^';
		// if (x == 0 and y == 3 and is_inside(x + dr[i], y + dc[i])) {
		// 	print(c);
		// 	print(x + dr[i], y + dc[i]);
		// 	print(s[x + dr[i]][y + dc[i]]);
		// }
	}
	return c;
}
inline bool check_valid(int x, int y) {
	if (s[x][y] == '#') return 0;
	int c = 0;
	lop(4) {
		c += is_inside(x + dr[i], y + dc[i]) and s[x + dr[i]][y + dc[i]] != '#';
		/*if (x == 0 and y == 3 and is_inside(x + dr[i], y + dc[i])) {
			print(x + dr[i], y + dc[i]);
			print(s[x + dr[i]][y + dc[i]]);
		}*/
	}
	/*if (x == 0 and y == 3) {dbg(c)}*/
	return c >= 2;
}

int dfs(int x, int y) {
	if (!is_inside(x, y) or s[x][y] == '#') return 0;
	if (vis[x][y]) return s[x][y] != '#';
	vis[x][y] = 1;

	int c = 0;
	lop(4) {
		int u = x + dr[i];
		int v = y + dc[i];
		c += dfs(u, v);

		// if (is_inside(u, v) and check_valid(u, v)) {
		// /*if (x == 0 and y == 3) {
		// dbg2(u, v)
		// }*/
		// c += dfs(u, v);
		// }
	}

	if (c < 2) return 0;
	/*if (x == 0 and y == 3) {
		dbg2(c, "x")
	}*/
	s[x][y] = '^';
	return 1;
	/*lop(4) {
		int u = x + dr[i];
		int v = y + dc[i];

		if (is_inside(u, v) and check_valid(u, v)) {
			dfs(u, v);
		}
	}*/
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		Case(cs++);
		cin >> n >> m;
		bool f = 0;
		lop(n) lopj(m) {
			cin >> s[i][j];
			if (s[i][j] == '^') f = 1;
		}

		if (n == 1 or m == 1) {
			if (f) no;
			else {
				yes;
				lop(n) {
					lopj(m) cout << s[i][j];
					cout << '\n';
				}
			}
			continue;
		}

		memset(vis, 0, sizeof vis);
		lop(n) {
			lopj(m) {
				if (!vis[i][j] and s[i][j] == '^') dfs(i, j);
			}
		}

		f = 1;
		lop(n) {
			lopj(m) {
				if (s[i][j] != '^') continue;
				// dbg3(i, j, count_tree(i, j))
				f &= count_tree(i, j) >= 2;
				// dbg3(i, j, count_tree(i, j))
			}
		}

		if (!f) no;
		else {
			yes;
			lop(n) {
				lopj(m) cout << s[i][j];
				cout << '\n';
			}
		}
	}

	return 0;
}
