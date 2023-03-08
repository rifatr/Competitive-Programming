// Problem: B. Take Your Places!
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// Time: 2021-08-29 20:50:43
// URL: https://codeforces.com/contest/1556/problem/B


#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "\t", dbg(y);
#define dbg3(x, y, z) cout << #x << " = " << x << "\t", dbg2(y, z);
#define ddbg(x) cout << #x << " = [ "; for(auto z : x) cout << z << ' '; cout << "]\n";
#else
#define dbg(x)
#define adbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#define ddbg(x)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for(int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ':'\n');}

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int tc;
	cin >> tc;
	
	while (tc--)
	{
		int n;
		cin >> n;
		
		vin pos[2];
		lop(n) {
			int x; cin >> x;
			x = x % 2;
			pos[x].pb(i);
		}
		int a = pos[0].size(), b = pos[1].size();
		
		if(abs(a - b) > 1) {
			print(-1);
			continue;
		}
		if(n <= 2) {
			print(0);
			continue;
		}
		
		ll res = 0, j = 1;
		for(int i : pos[a >= b]) {
			res += abs(i - j);
			j += 2;
		}
		
		if(a == b) {
			ll res2 = 0, j = 1;
			for(int i : pos[0]) {
				res2 += abs(i - j);
				j += 2;
			}
			res = min(res, res2);
		}
		
		print(res);
	}
	
	return 0;
}
