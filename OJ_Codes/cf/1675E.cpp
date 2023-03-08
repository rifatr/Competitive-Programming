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
// sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

map <char, char> par;
char pre(char x) {
	return par[x] == x ? x : par[x] = pre(par[x]);
}
void Uni(char u, char v) {
	par[pre(u)] = pre(v);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n, k; cin >> n >> k;
		string s; cin >> s;

		for (char c = 'a'; c <= 'z'; c++) par[c] = c;

		vin pos[26];
		lop(n) pos[s[i] - 'a'].pb(i);

		lop(n) {
			if (pos[s[i] - 'a'].size() == 0) continue;

			int p = i, q = i + 1;
			while (q < n) {
				if (pos[s[q] - 'a'].size() == 0) q++;
				else {
					if (s[q] > s[p] and s[q] - 'a' <= k) {
						p = q;
					}
					else break;
				}
				q++;
			}

			int j = s[p] - 'a';
			dbg3(i, p, j)
			while (k > 0 and j > 0) {
				while (pos[j].size()) {
					pos[j - 1].pb(pos[j].back());
					pos[j].pop_back();
				}
				pos[j].clear();
				j--, k--;
			}
		}

		/*while (k > 0) {
			char p = pre(s[0]);
			for (char c : s) {
				if (pre(c) == 'a') continue;

				if (p == 'a') p = pre(c);
				else {
					char d = pre(c);
					if (d > p and d - 'a' <= k) p = d;
				}
			}

			if (p == 'a') k = 0;
			while (p > 'a' and k) {
				Uni(p, p - 1);
				p--;
				k--;
			}
		}*/

		/*		while (k > 0) {
					char p = s[0];
					for (int i = 0; i < n; i++) {
						p = pre(s[i]);
						if (p != 'a') break;
					}
					if (p == 'a') break;
					for (char c : s) {
						if (pre(c) - 'a' <= k and pre(c) > pre(p)) p = c;
					}

					dbg3(k, p, pre(p))
					if (pre(p) == 'a') break;
					char c = pre(p);
					while (c > 'a' and k--) {
						Uni(c, c - 1);
						c--;
					}
				}

				lop(n) {
					if (k <= 0) break;
					if (pre(s[i]) == 'a') continue;

					char c = pre(s[i]);
					dbg3(s[i], c, k)
					while (c > 'a' and k--) {
						Uni(c, c - 1);
						c--;
						dbg2(c, k)
					}
					dbg(k)
				}
				dbg(pre)*/

		lop(26) {
			for (int j : pos[i]) s[j] = 'a' + i;
		}

		print(s);
	}

	return 0;
}
