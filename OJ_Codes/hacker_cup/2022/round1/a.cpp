#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
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

unordered_map <int, vin> aa, bb;

int main()
{
	// freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		Case(cs++);

		int n, k; cin >> n >> k;
		vin a(n), b(n);
		lop(n) cin >> a[i];
		lop(n) cin >> b[i];

		if (!k) {
			a == b ? yes : no;
			continue;
		}
		if (k == 1 and a == b) {
			count(all(a), a[0]) == n ? yes : no;
			continue;
		}
		if (n == 2) {
			((a == b) == !(k % 2)) or (a[0] == a[1] and a == b) ? yes : no;
			continue;
		}

		aa.clear();
		bb.clear();
		lop(n) {
			aa[a[i]].pb(a[(i + 1) % n]);
			bb[b[i]].pb(b[(i + 1) % n]);
		}
		for (auto &z : aa) sort(all(z.ss));
		for (auto &z : bb) sort(all(z.ss));

		aa == bb ? yes : no;
	}

	return 0;
}