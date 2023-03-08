// Problem: Salary Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1144
// Time: 2022-02-03 15:40:41

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

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifndef ONLINE_JUDGE
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>

using namespace __gnu_pbds;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, q;
	cin >> n >> q;
	int ar[n + 1];
	ordered_set st;
	lop(n) {
		cin >> ar[i + 1];
		st.insert({ar[i + 1], i + 1});
	}
	
	while(q--) {
		char o; int l, r;
		cin >> o >> l >> r;
		
		if(o == '!') {
			//make ar[l] = r
			
			st.erase(st.lower_bound({ar[l], 1}));
			ar[l] = r;
			st.insert({r, l});
		}
		else {
			//print range of [l, r]
			
			int a = st.order_of_key({l, 1});
			int b = st.order_of_key({r + 1, 1});
			print(b - a);
		}
	}

	return 0;
}
