// Problem: C. Number of Minimums on a Segment
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
// Time: 2022-01-27 14:12:58

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

const int N = 1e5 + 5;
int n, a[N];
pii sum[4 * N];

void build(int i, int l, int r) {
	if(l == r) {
		sum[i] = {a[l], 1};
		return;
	}
	
	int mid = (l + r) / 2, p = 2 * i, q = 2 * i + 1;
	build(p, l, mid);
	build(q, mid + 1, r);
	if(sum[p].ff < sum[q].ff) sum[i] = sum[p];
	else if(sum[p].ff > sum[q].ff) sum[i] = sum[q];
	else sum[i] = {sum[p].ff, sum[p].ss + sum[q].ss};
}

pii query(int i, int left, int right, int l, int r) {
	if(r < left or l > right) return {2e9, 0};
	if(l >= left and r <= right) return sum[i];
	
	int md = (l + r) / 2;
	pii x = query(2 * i, left, right, l, md), y = query(2 * i + 1, left, right, md + 1, r);
	if(x.ff < y.ff) return x;
	else if(x.ff > y.ff) return y;
	else return {x.ff, x.ss + y.ss};
}

void update(int i, int ind, int x, int l, int r) {
	if(r < ind or l > ind) return;
	if(l == r) {
		sum[i] = {x, 1};
		return;
	}
	
	int mid = (l + r) / 2, p = 2 * i, q = 2 * i + 1;
	update(p, ind, x, l, mid);
	update(q, ind, x, mid + 1, r);
	if(sum[p].ff < sum[q].ff) sum[i] = sum[p];
	else if(sum[p].ff > sum[q].ff) sum[i] = sum[q];
	else sum[i] = {sum[p].ff, sum[p].ss + sum[q].ss};
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc = 1, t = 1;
	// cin >> tc;

	while (tc--)
	{
		int q;
		cin >> n >> q;
		lop(n) cin >> a[i + 1];
		
		build(1, 1, n);
		
		while(q--) {
			int c;
			cin >> c;
			
			if(c == 1) {
				int p, x;
				cin >> p >> x;
				p++;
				update(1, p, x, 1, n);
			}
			else {
				int l, r;
				cin >> l >> r;
				l++;
				print(query(1, l, r, 1, n));
			}
		}
	}

	return 0;
}
