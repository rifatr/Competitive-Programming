// Problem: Array Queries
// Contest: LightOJ
// URL: https://lightoj.com/problem/array-queries
// Time: 2022-01-02 02:30:53

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

const int N = 1e5 + 10;
int n, a[N], minel[4 * N];

void build(int i, int l, int r) {
	if(l == r) {
		minel[i] = a[l];
		return;
	}
	
	int md = (l + r) / 2;
	build(2 * i, l, md);
	build(2 * i + 1, md + 1, r);
	minel[i] = min(minel[2 * i], minel[2 * i + 1]);
}

int query(int i, int p, int q, int l, int r) {
	if(l > q or r < p or l > r) return 1e8;
	if(l >= p and r <= q) return minel[i];
	
	int md = (l + r) / 2;
	int x = query(2 * i, p, q, l, md), y = query(2 * i + 1, p, q, md + 1, r);
	return min(x, y);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, tt = 1;
	cin >> tc;

	while (tc--)
	{
		int q;
		cin >> n >> q;
		lop(n) cin >> a[i + 1];
		
		build(1, 1, n);
		Case(tt++);
		while(q--) {
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r, 1, n) << '\n';
		}
	}

	return 0;
}
