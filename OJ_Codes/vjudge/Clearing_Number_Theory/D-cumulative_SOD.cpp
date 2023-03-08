// Time: 2022-06-12 14:49:46	Problem: D - A New Function 
// URL: https://vjudge.net/contest/498440#problem/D

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

inline ll cal(ll x) {
    return (x * (x + 1)) / 2;
}

inline ll range_sum(ll l, ll r) {
    return cal(r) - cal(l - 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
	    Case(cs++);
		
		ll n; cin >> n;
		ll sum = 0;
		
		for(ll i = 2; i * i <= n; i++) {
		    sum += (n / i - 1) * i; // i ashbe n/i - 1 bar
		    
		    ll l = n / (i + 1) + 1, r = n / i; // n / (i + 1) + 1 theke n / i porjonto ashbe i-1 bar kore
		    if(i != n / i) // avoid overcount for sqrt(n)
		        sum += range_sum(l, r) * (i - 1);
		}
		    
		print(sum);
	}

	return 0;
}
