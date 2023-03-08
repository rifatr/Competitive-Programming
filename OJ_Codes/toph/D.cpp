// Time: 2022-07-01 17:21:59	Problem: D - D 
// URL: https://vjudge.net/contest/502345#problem/D

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

	int n, f;
	cin >> n >> f;
	
	vector <int> h(n);
	lop(n) cin >> h[i];
	
	vector <int> ans;
	int nw = f;
	while(h.size()) {
	    int to = h[0];
	    // h.erase(h.begin());
	    
	    if(nw > to) {
	        while(nw > to) {
	            nw--;
	            auto  it = find(all(h), nw);
	            dbg2(nw, to)
	            if(it != h.end()) {
	                dbg(*it)
	                ans.pb(nw);
	                h.erase(it);
	            }
	        }
	    }
	    else {
	        while(nw < to) {
	            nw++;
	            
	            auto it = find(all(h), nw);
	            dbg(nw);
	            if(it != h.end()) {
	                ans.pb(nw);
	                dbg(*it);
	                h.erase(it);
	            }
	        }
	    }
	    
	    nw = to;
	    // ans.pb(nw);
	    
	    dbg2(h, ans) dbg(nw)
	}
	
	print(ans);

	return 0;
}
