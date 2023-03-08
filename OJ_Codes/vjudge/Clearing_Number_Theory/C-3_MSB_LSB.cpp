// Time: 2022-06-11 02:24:21	Problem: C - Leading and Trailing 
// URL: https://vjudge.net/contest/498440#problem/C

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

ll bigmod(ll a, ll b, ll mod) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll first3(ll n, ll k) {
/* 
    n^k = y * 10^x
so, log(n^k) = log(y * 10^x)
so, k*log(n) = log(y) + x*log10 = log(y) + x

assume, y = 1, x = k * log(n)
now, log(y) = k * log(n) - floor(x)
and, y = 10^log(y)
now if we multiply with 100, we will get 3 digits
*/  
    
    double x = k * log10(n);
    double logy = x - floor(x);
    double y = pow(10, logy); 
    return y * 100;
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
	    Case(cs++);
		
		ll n, k; cin >> n >> k;
		ll last3 = bigmod(n, k, 1000);
		printf("%lld %03lld\n", first3(n, k), last3);
	}

	return 0;
}
