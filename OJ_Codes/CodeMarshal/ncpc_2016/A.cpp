// Time: 2022-08-26 15:37:29	Problem: A. XOR Sequence Revisited 
// URL: https://algo.codemarshal.org/contests/ncpc-uap-2016/problems/A

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
		ll l, r; cin >> l >> r;	
		// if(r - l + 1 >= 20) {
		    // print(0);
		    // continue;
		// }
			
		ll x = (l-1)/4 * 4  + 1 ;
		dbg(x)
		map<ll,ll>mp ;
		mp[0] = 1;
		mp[x] = 0;
		for (ll i = x + 1 ;  i<= x + 25 ; i++) mp[i] = mp[i-1] ^ i ;
		ll ans = mp[l] ;
		for (ll i = l ; i<= r and ans; i++){
		    ans &= mp[i] ;
		}
		
		
		print(ans);
	}

	return 0;
}