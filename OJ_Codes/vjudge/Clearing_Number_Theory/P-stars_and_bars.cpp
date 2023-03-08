// Time: 2022-06-07 00:31:36	Problem: P - Problem Makes Problem 
// URL: https://vjudge.net/contest/498440#problem/P

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

const ll N = 2e6 + 10, mod = 1e9 + 7;
ll fact[N];

ll bigmod(ll a, ll b) {
    if(!b) return 1;
    ll x = bigmod(a, b / 2);
    x = (x * x) % mod;
    if(b & 1) x = (x * a) % mod;
    return x; 
}

ll nCr(ll n, ll r) {
    ll x = fact[n];
    ll y = (fact[r] * fact[n - r]) % mod;
    
    return (x * bigmod(y, mod - 2)) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fact[0] = 1;
	for(int i = 1; i < N; i++)
	    fact[i] = (fact[i - 1] * i) % mod;

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		ll n, k; cin >> n >> k;
		Case(cs++);
		print(nCr(n + k - 1, k - 1));
	}

	return 0;
}
