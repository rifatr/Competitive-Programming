// Problem: D2. Seating Arrangements (hard version)
// Contest: Codeforces - Codeforces Global Round 16
// Time: 2021-09-12 20:35:37
// URL: https://codeforces.com/contest/1566/problem/D2

#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifndef ONLINE_JUDGE
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
map <int, set <int>> pos, ps;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n, m;
		cin >> m >> n;
		int a[n * m], b[n * m];
		lop(m * n) {
			cin >> a[i];
			a[i]--;
			b[i] = a[i];
		}
		
		lop(n * m) pos[a[i]].insert(i);
		ps = pos;
		sort(a, a + (n * m));
		
		int asign[m][n], p = n * m - 1;
		/*for(int i = m - 1; i >= 0; i--)*/ lop(m) {
			p = (i + 1) * n - 1;
			asign[i][n - 1] = *pos[a[p]].begin();
			pos[a[p]].erase(pos[a[p]].begin());
			p--;
			for(int j = n - 2; j >= 0; j--) {
				auto it = pos[a[p]].lower_bound(asign[i][j + 1]);
				if(it == pos[a[p]].end()) {
					dbg2(i, j) dbg2(p, asign[i][j + 1])
					it = pos[a[p]].begin();
				}
				
				asign[i][j] = *it;
				pos[a[p]].erase(it);
				p--;
			}
		}
		
		// lop(m) {
			// lopj(n - 1) {
				// if(asign[i][j] > asign[i][j + 1]) continue;
// 				
				// for(int p = i; p < m; p++) {
					// for(int q = j + 2; q)
				// }
			// }
		// }
		lop(m) print(asign[i], n);
		
		ll sum = 0;
		lop(m) {
			lopj(n) {
				for(int k = j + 1; k < n; k++)
					sum += (asign[i][k] > asign[i][j]);
			}
		}
		print(sum);
		// dbg(pos)
		
		// bool seat[n];
		/*ll sum = 0, seat[m][n];
		memset(seat, 0, sizeof seat);
		// for(int k = 0; k < m; k++) {
			lop(n * m) {
				int p = pos[b[i]].back(), x = p % n, y = p / n;
				pos[b[i]].pop_back();
				// dbg2(b[i], p) dbg3(p, x, y)
				
				for(int j = 0; j < x; j++) {
					sum += !!seat[y][j];
				}
				seat[y][x] = 1;
			}
		// }
		
		print(sum);*/
		pos.clear();
		ps.clear();
	}

	return 0;
}
