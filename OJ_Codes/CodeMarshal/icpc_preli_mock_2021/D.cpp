// Time: 2022-09-02 15:53:11	Problem: D. Stick to Triangle 
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-21-preli-mock/problems/D

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

ll pw(ll a, ll b) {
    ll s = 1;
    lop(b) s *= a;
    return s;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;
	
    vll a{0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    for(int n = 11; n < 4e5; n++) {
        a.pb(a[n - 2] + a[n - 3] + a[n - 4] - a[n - 5] - a[n - 6] - a[n - 7] + a[n - 9]);
    }

	while (tc--)
	{
		ll n;
		cin >> n;
		
		Case(cs++);
		print(a[n]);
	}

	return 0;
}

// ll x = pw(n, 3) * (1 + n - pw(n, 4));
		// ll y = pw(1 - x, 3) * pw(1 + x, 2) * (1 + x + x) * (1 + x + x * x);
		// dbg2(x, y)
