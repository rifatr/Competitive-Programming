#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case #" << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpii vector <pii>

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

const int N = 1e6 + 10;
multiset <pii> a, b;
int md[N], of[N], n, m;
vpii uu;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, t = 1;
	cin >> tc;

	while (tc--)
	{
		a.clear(); b.clear();
		cin >> m >> n;
		lop(n) {
			cin >> md[i];
			a.insert({md[i], 0});
		}

		int ans = 0;
		for (int round = 0; round < m; round++) {
			lop(n) {
				cin >> of[i];
				auto it = a.lower_bound({of[i], 0});
				if (it -> ff == of[i]) {
					b.insert(*it);
					a.erase(it);
				}
				else {
					uu.pb({of[i], i});
				}
			}
			while (uu.size()) {
				if (a.begin() -> ss) {
					ans++;
				}
				b.insert({uu.back(). ff, uu.back().ff != md[uu.back().ss]});
				a.erase(a.begin());
				uu.pop_back();
			}
			a = b;
			b.clear();
		}

		Case(t++);
		print(ans);
	}

	return 0;
}
