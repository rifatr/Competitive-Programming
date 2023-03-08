// Time: 2022-06-10 00:35:01	Problem: H - Trailing Zeroes (II) 
// URL: https://vjudge.net/contest/498440#problem/H

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

const int N = 1e6 + 10;
pll t5[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for(int i = 2; i < N; i++) {
	    int j = i;
	    while(j % 2 == 0) {
	        j /= 2;
	        t5[i].ff++;
	    }
	    while(j % 5 == 0) {
	        j /= 5;
	        t5[i].ss++;
	    }
	    
	    t5[i].ff += t5[i - 1].ff;
	    t5[i].ss += t5[i - 1].ss;
	}

	int tc, cs = 1;
	cin >> tc;
	
	auto mn = [&] (int n) {
	    return min(t5[n].ff, t5[n].ss);
	};

	while (tc--)
	{
		Case(cs++);
		
		ll n, r, p, q; 
		cin >> n >> r >> p >> q;
		
		ll two = t5[n].ff - t5[r].ff - t5[n - r].ff;
		ll five = t5[n].ss - t5[r].ss - t5[n - r].ss;
		
		two += (t5[p].ff - t5[p - 1].ff) * q;
		five += (t5[p].ss - t5[p - 1].ss) * q;
		
		print(min(two, five));
	}

	return 0;
}