// Time: 2022-06-06 00:32:11	Problem: I - Trailing Zeroes (III) 
// URL: https://vjudge.net/contest/498440#problem/I

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

int trailing_zeros(int n) {
    int c = 0;
    for(int i = 5; i <= n; i *= 5)
        c += n / i;
    return c;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		int n; cin >> n;
		
		int ans = -1, lo = 5, hi = 1e9;
		while(lo <= hi) {
		    int md = (lo + hi) >> 1;
		    if(trailing_zeros(md) >= n) {
		        hi = md - 1;
		        ans = md;
		    }
		    else lo = md + 1;
		}
		
		Case(cs++);
		if(trailing_zeros(ans) == n) print(ans);
		else print("impossible");
	}

	return 0;
}