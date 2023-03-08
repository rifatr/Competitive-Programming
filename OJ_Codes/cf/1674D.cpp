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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		map <int, vin> ind;
		vin a(n);
		lop(n) {
			cin >> a[i];
			ind[a[i]].pb(i);
		}

		if (n < 3) {
			yes;
			continue;
		}

		for (auto &z : ind) sortd(z.ss);
		vin b = a;
		sort(all(b));

		int i = 0;
		if (n & 1) {
			if (ind[b[0]].back() != 0) {
				no;
				continue;
			}
			i = 1;
			ind[b[0]].pop_back();
		}

		// dbg(b) dbg(ind)
		int k = 0;
		while (i < n) {
			int j = i + 1;
			if (ind[b[i]].back() == i or (k % 2 == 0 and ind[b[i]].back() == i + 1) or (k % 2 and ind[b[i]].back() == i - 1)) {
				ind[b[i]].pop_back();
			}
			else {
				// dbg2(i, k)
				// dbg2(b[i], ind[b[i]].back())
				no;
				goto shesh;
			}

			i++, k++;
		}

		yes;
shesh:;
	}

	return 0;
}