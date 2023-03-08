// Problem: Histogram
// Contest: LightOJ
// URL: https://lightoj.com/problem/histogram
// Time: 2022-02-01 11:43:02

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

const int  N = 3e4 + 10;
int n, mnel[4 * N], a[N];

void build(int i, int l, int r) {
	if(l == r) {
		mnel[i] = l;
		return;
	}
	
	int mid = (l + r) / 2;
	build(2*i, l, mid);
	build(2*i+1, mid + 1, r);
	mnel[i] = a[mnel[2*i]] < a[mnel[2*i+1]] ? mnel[2*i] : mnel[2*i+1];
}

int findmin(int i, int left, int right, int l, int r) {
	if(l > right or r < left) return 0;
	if(l >= left and r <= right) return mnel[i];
	
	int mid = (l + r) / 2;
	int x = findmin(2*i, left, right, l, mid);
	int y = findmin(2*i+1, left, right, mid+1, r);
	return a[x] < a[y] ? x : y;
}

int findans(int l, int r) {
	if(l > r) return 0;
	// if(l == r) return a[l];
	
	int mn = findmin(1, l, r, 1, n);
	dbg3(l, r, mn)
	int ans = a[mn] * (r - l + 1);
	int left = findans(l, mn - 1), right = findans(mn + 1, r);
	return max({ans, left, right});
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, t = 1;
	cin >> tc;
	a[0] = INT_MAX;

	while (tc--)
	{
		cin >> n;
		lop(n) cin >> a[i + 1];
		
		build(1, 1, n);
		Case(t++);
		print(findans(1, n));
	}

	return 0;
}
