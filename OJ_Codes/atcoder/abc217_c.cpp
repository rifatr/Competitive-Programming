// Problem: C - Inverse of Permutation
// Contest: AtCoder - AtCoder Beginner Contest 217
// Time: 2021-09-04 18:01:21
// URL: https://atcoder.jp/contests/abc217/tasks/abc217_c


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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	int q[n + 1];
	for(int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		q[p] = i;
	}
	
	print(q + 1, n);

	return 0;
}

/* Infos
~ 4 Direction
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

~ 8 Direction
int dr[] = {1,-1,0,0,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1,1,-1};

~ Knight Direction
int dr[] = {1,-1,1,-1,2,2,-2,-2};
int dc[] = {2,2,-2,-2,1,-1,1,-1};

~ Hexagonal Direction
int dr[] = {2,-2,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1};

~ bitmask operations
int Set(int n, int pos) { return n = n | (1 << pos); }
int reset(int n, int pos) { return n = n & ~(1 << pos); }
bool check(int n, int pos) { return (bool)(n & (1 << pos)); }
bool isPower2(int x) { return (x && !(x & (x - 1))); }
ll LargestPower2<=x(ll x) { for(int i = 1; i <= x / 2; i *= 2) x = x | (x >> i); return (x + 1) / 2;}
*/