// Problem: Curious Robin Hood
// Contest: LightOJ
// URL: https://lightoj.com/problem/curious-robin-hood
// Time: 2022-01-26 02:18:00

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

const int N = 1e5 + 5;
int n, q, a[N], sum[4 * N];

void build(int i, int l, int r) {
	if(l == r) {
		sum[i] = a[l];
		return;
	}
	
	int mid = (l + r) / 2;
	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
	sum[i] = sum[2 * i] + sum[2 * i + 1];
}

int query(int i, int left, int right, int l, int r) {
	if(r < left or l > right) return 0;
	if(l >= left and r <= right) return sum[i];
	
	int mid = (l + r) / 2;
	return query(2 * i, left, right, l, mid) + query(2 * i + 1,  left, right, mid + 1, r);
}

void update(int i, int p, int x, int l, int r) {
	if(r < p or l > p) return;
	if(l == r) {
		sum[i] += x;
		return;
	}
	
	int mid = (l + r) / 2;
	update(2 * i, p, x, l, mid);
	update(2 * i + 1, p, x, mid + 1, r);
	sum[i] = sum[2 * i] + sum[2 * i + 1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, t = 1;
	cin >> tc;

	while (tc--)
	{
		cin >> n >> q;
		lop(n) cin >> a[i + 1];
		
		build(1, 1, n);
		Case(t++);
		
		while(q--) {
			int c;
			cin >> c;
			
			if(c == 1) {
				int p;
				cin >> p;
				p++;
				print(a[p]);
				update(1, p, -a[p], 1, n);
				a[p] = 0;
			}
			else if(c == 2) {
				int p, x;
				cin >> p >> x;
				p++;
				update(1, p, x, 1, n);
				a[p] += x;
			}
			else {
				int l, r;
				cin >> l >> r;
				l++, r++;
				print(query(1, l, r, 1, n));
			}
		}
	}

	return 0;
}
