// Problem: C - Neo-lexicographic Ordering
// Contest: AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest 219）
// Time: 2021-09-18 19:50:37
// URL: https://atcoder.jp/contests/abc219/tasks/abc219_c

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

string s;
int pos[130];
bool cmp(string &a, string &b) {
	for(int i = 0; i < min(a.size(), b.size()); i++) {
		if(a[i] != b[i]) return pos[a[i]] < pos[b[i]];
	}
	
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	lop(26) pos[s[i]] = i + 1;
	
	int n;
	cin >> n;
	string t[n];
	lop(n) cin >> t[i];
	
	sort(t, t + n, cmp);
	print(t, n);

	return 0;
}
