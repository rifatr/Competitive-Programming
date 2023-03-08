// Problem: List Removals
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1749
// Time: 2022-02-03 15:31:48

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

const int N = 2e5 + 10;
int n, bit[N], ind[N];

void edit(int pos, int x) {
    while (pos < N) {
        bit[pos] += x;
        pos += pos & -pos;
    }
}

int sum(int pos) {
    int s = 0;
    while (pos) {
        s += bit[pos];
        pos -= pos & -pos;
    }

    return s;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	int k = 1;
	lop(n) {
		cin >> ind[k];
		edit(k++, 1);
	}
	
	lop(n) {
		int p;
		cin >> p;
		
		int lo = 1, hi = N - 1, mid, pos = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			int s = sum(mid);
			if(s >= p) {
				hi = mid - 1;
				pos = mid;
			}
			else lo = mid + 1;
		}
		
		print(ind[pos]);
		edit(pos, -1);
	}

	return 0;
}
