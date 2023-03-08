// Problem: Dynamic Range Minimum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1649
// Time: 2022-02-03 15:18:29

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

using namespace std;

const int  N = 2e5 + 10;
int n, maxel[4 * N], a[N];

void build(int i, int l, int r) {
	if(l == r) {
		maxel[i] = l;
		return;
	}
	
	int mid = (l + r) / 2;
	build(2*i, l, mid);
	build(2*i+1, mid + 1, r);
	maxel[i] = a[maxel[2*i]] < a[maxel[2*i+1]] ? maxel[2*i] : maxel[2*i+1];
}

int findmax(int i, int left, int right, int l, int r) {
	if(l > right or r < left) return 0;
	if(l >= left and r <= right) return maxel[i];
	
	int mid = (l + r) / 2;
	int x = findmax(2*i, left, right, l, mid);
	int y = findmax(2*i+1, left, right, mid+1, r);
	return a[x] < a[y] ? x : y;
}

void update(int i, int p, int x, int l, int r) {
	if(l > p or r < p) return;
	if(l == r) {
		a[p] = x;
		return;
	}
	
	int mid = (l + r) / 2;
	update(2*i, p, x, l, mid);
	update(2*i+1, p, x, mid + 1, r);
	maxel[i] = a[maxel[2*i]] < a[maxel[2*i+1]] ? maxel[2*i] : maxel[2*i+1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	a[0] = INT_MAX;

	int q;
	cin >> n >> q;
	lop(n) cin >> a[i + 1];
	build(1, 1, n);
	
	while(q--) {
		int c, l, r;
		cin >> c >> l >> r;
		
		if(c & 1) update(1, l, r, 1, n);
		else print(a[findmax(1, l, r, 1, n)]);
	}

	return 0;
}
