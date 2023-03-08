// Time: 2022-09-03 15:14:31	Problem: I. Hovercraft 
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-21-preli/problems/I

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

#define ld long double

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	// int tc;
	// cin >> tc;

	while (1)
	{
		int l, w;
		cin >> l >> w;
		if(!l and !w) break;
		
		auto cal = [&] (ld d) {
		    ld r = l - d;
		    if(r > d) return (ld)1e9;
		    ld c = sqrt(d * d - r * r);
		    ld res = d + d + w - c;
		    return res;  
		};
		
		ld lo = 0, hi = l, ans = l + w, md;		
		lop(100) {
		    md = (lo + hi) / 2;
		    ld res = cal(md);
		    
		    if(res < ans) {
		        ans = res;
		        hi = md;
		    }  
		    else lo = md;
		}
		
		cout << fixed << setprecision(4);
		cout << ans << '\n';	
		// dbg(md)	
	}

	return 0;
}
