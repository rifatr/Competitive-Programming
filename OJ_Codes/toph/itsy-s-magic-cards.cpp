// Time: 2022-06-14 13:50:00	Problem: Itsy's Magic Cards 
// URL: https://toph.co/p/itsy-s-magic-cards

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

	int n, m; cin >> n >> m;
	pii nv[m];
	lop(m) {
	    char a, b; cin >> a >> b;
	    nv[i] = {a - 'A', b - 'A'};
	}
	
	ddbg(nv)
	auto isval = [&] (int mask) {
	    vin tm;
	    for(int i = 0; i < n; i++) {
	        if(mask & (1 << i)) tm.pb(i);
	    } 
	    
	    for(int i = 0; i < (int) tm.size() - 1; i++) {
	        pii x = {tm[i], tm[i + 1]}, y = {tm[i + 1], tm[i]};
	        dbg2(x,y)
	        if(count(nv, nv + m, x) or count(nv, nv + m, y)) return 0;
	    }
	    dbg(tm) 
	    return (int) tm.size();
	};
	
	int ans = 0;
	for(int mask = 0; mask < 1 << n; mask++) 
	    ans = max(ans, isval(mask));
	print(ans);

	return 0;
}
