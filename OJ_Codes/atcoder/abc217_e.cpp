// Problem: E - Sorting Queries
// Contest: AtCoder - AtCoder Beginner Contest 217
// Time: 2021-09-04 18:01:28
// URL: https://atcoder.jp/contests/abc217/tasks/abc217_e


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

const int N = 2e9;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;
	
	multiset <pii> st;

	for(int i = 1; i <= tc; i++)
	{
		int q;
		cin >> q;
		
		if(q == 1) {
			int x;
			cin >> x;
			
			st.insert({N + i, x});
		}
		else if(q == 2) {
			print(st.begin() -> ss);
			st.erase(st.begin());
		}
		else {
			while(st.size() and (--st.end()) -> ff > N) {
				int x = (--st.end()) -> ss;
				st.erase(--st.end());
				st.insert({x, x});
			}
		}
	}

	return 0;
}