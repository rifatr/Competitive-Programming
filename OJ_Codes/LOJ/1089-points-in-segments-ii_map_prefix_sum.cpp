// Problem: Points in Segments (II)
// Contest: LightOJ
// URL: https://lightoj.com/problem/points-in-segments-ii
// Time: 2022-02-01 23:41:40

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ":\n"

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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, t = 1;
	cin >> tc;

	while (tc--)
	{
		int n, q;
		cin >> n >> q;
		
		map <int, int> cnt;
		lop(n) {
			int l, r;
			cin >> l >> r;
			cnt[l]++;
			cnt[r + 1]--;
		}
		
		auto it = cnt.begin(), it2 = it++;
		while(it != cnt.end()) {
			it -> ss += it2 -> ss;
			it++, it2++;
		}
		
		Case(t++);
		while(q--) {
			int p;
			cin >> p;
			
			print((--cnt.upper_bound(p)) -> ss);
		}
	}

	return 0;
}
