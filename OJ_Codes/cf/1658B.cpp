#include <bits/stdc++.h>

#define ll 			long long
#define pb 			push_back
#define ff 			first
#define ss 			second

#define yes 		cout << "YES\n"
#define no 			cout << "NO\n"
#define Case(i) 	cout << "Case " << int(i) << ": "

#define lop(n) 		for (int i = 0; i < n; i++)
#define lopj(n) 	for (int j = 0; j < n; j++)

#define all(x) 		x.begin(), x.end()
#define sortd(x) 	sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin 		vector <int>
#define vll 		vector <ll>
#define pll 		pair <ll, ll>
#define pii 		pair <int, int>
#define vpll 		vector <pll>

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

const ll mod = 998244353;

ll fct(ll n) {
	if (n <= 1) return 1;

	ll x = 1;
	lop(n - 1) x = (x * (i + 2)) % mod;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		ll n;
		cin >> n;
		print(n & 1 ? 0 : (fct(n / 2) * fct(n / 2)) % mod);
	}

	return 0;
}
