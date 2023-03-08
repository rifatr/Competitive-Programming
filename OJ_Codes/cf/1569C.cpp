// Problem: C. Jury Meeting
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// Time: 2021-09-08 21:28:15
// URL: https://codeforces.com/contest/1569/problem/C

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

const ll N = 2e5 + 7, mod = 998244353;
ll fact[N];

ll inverse_mod(ll a, ll b) {
	return 1 < a ? b - inverse_mod(b % a, a) * b / a: 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fact[0] = 1;
	for(ll i = 1; i < N; i ++) fact[i] = (fact[i - 1] * i) % mod;
	

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		ll a[n];
		lop(n) cin >> a[i];
		sort(a, a + n, greater <ll> ());
		
		if(a[0] == a[1]) {
			print(fact[n]);
			continue;
		}
		if(a[0] - a[1] > 1) {
			print(0);
			continue;
		}
		
		auto npr = [&] (ll nn, ll rr) {
			return (fact[nn] * inverse_mod(fact[nn - rr], mod)) % mod;
		};
		
		// if(r == 0) {
			// print((fact[n] - ((fact[n - 1] * fact[p]) % mod) + mod) % mod);
			// continue;
		// }
		
		ll p, q = 0;
		lop(n) q += (a[i] == a[1]);
		
		ll ans = fact[n];
		for(int i = n; i > q; i--) {
			ll z = (fact[n - q - 1] * npr(i - 1, q)) % mod;
			ans = (ans - z + mod) % mod;
		}
		
		print(ans);
	}

	return 0;
}
