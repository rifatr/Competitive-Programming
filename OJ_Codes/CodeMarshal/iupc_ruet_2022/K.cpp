// Time: 2023-01-17 23:21:21	Problem: K. Change the username 
// URL: https://algo.codemarshal.org/contests/ruet-2022/problems/K

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
		int n; cin >> n;
		map <string, string> prev;
		set <string> notused, used;
		
		lop(n) {
		    int k; string a;
		    cin >> k >> a;
		    
		    if(k == 1) {
		        string b; cin >> b;
		        
		        if(used.count(b)) continue;
		        used.erase(a);
		        notused.insert(a);
		        used.insert(b);
		        notused.erase(b);
		        
		        if(!prev[a].size()) prev[a] = a;
		        prev[b] = prev[a];
		    }
		    else {
		        if(notused.count(a)) print("Not in use!");
		        else if(!prev[a].size()) print(a);
		        else print(prev[a]);
		    }
		}
	}

	return 0;
}
