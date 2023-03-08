// Problem: C. Delete Two Elements
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// Time: 2021-10-16 16:42:35
// URL: https://codeforces.com/contest/1598/problem/C

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

struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
// http://xorshift.di.unimi.it/splitmix64.c
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM =
chrono::steady_clock::now().time_since_epoch().
count();
return splitmix64(x + FIXED_RANDOM);
}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		ll a[n], x = 0;
		unordered_map <int, int, custom_hash> cnt;
		lop(n) {
		    cin >> a[i];
		    cnt[a[i]]++;
		    x += a[i];
		}
		
		if((2 * x) % n ) {
		    print(0);
		    continue;
		}
		
		ll ans = 0, y = (2 * x) / n;
		sort(a, a + n);
		lop(n) {
		    if(a[i] * 2 == y) {
		        ans += ((ll) cnt[a[i]] * (cnt[a[i]] - 1)) / 2;
		    }
		    else {
		        ans += (ll) cnt[a[i]] * cnt[y - a[i]];
		    }
		    cnt[a[i]] = cnt[y - a[i]] = 0;
		}
		
		print(ans);
	}

	return 0;
}
