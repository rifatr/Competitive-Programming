#include <bits/stdc++.h>

#define ll      long long
#define pb      push_back
#define ff      first
#define ss      second

#define yes     cout << "YES\n"
#define no      cout << "NO\n"
#define Case(i)   cout << "Case " << int(i) << ": "

#define lop(n)    for (int i = 0; i < n; i++)
#define lopj(n)   for (int j = 0; j < n; j++)

#define all(x)    x.begin(), x.end()
#define sortd(x)  sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin     vector <int>
#define vll     vector <ll>
#define pll     pair <ll, ll>
#define pii     pair <int, int>
#define vpll    vector <pll>

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

int Set(int n, int pos) { return n = n | (1 << pos); }
int reset(int n, int pos) { return n = n & ~(1 << pos); }
bool check(int n, int pos) { return (bool)(n & (1 << pos)); }

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int l, r;
		cin >> l >> r;
		int n = r - l + 1, a[n];
		lop(n) cin >> a[i];

		int ans = 0;
		if (!count(a, a + n, 0)) {
			int x = *max_element(a, a + n);
			lop(n) a[i] ^= x;
			ans = x;
		}

		sort(a, a + n);
		unordered_set <int> st(a, a + n);
		vin nai;
		lop(n) {
			if (st.find(i) == st.end()) nai.pb(i);
		}

		for (int kk : nai) {
			bool f = 1;
			int x = kk ^ a[n - 1];
			for (int k : a)
				f &= (k ^ x) < n;

			if (f) {
				print(ans ^ x);
				goto shesh;
			}
		}

		print(ans);
shesh:;
	}

	return 0;
}
