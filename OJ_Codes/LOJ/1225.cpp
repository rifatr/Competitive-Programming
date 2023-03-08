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

const ll inf = 1e18, N = 1e6 + 9;
bitset <N> mark;
vector <int> prime;

void sieve()
{
	int i, j, limit = sqrt(N * 1.0);

	mark[0] = mark[1] = true;

	for (i = 4; i <= N; i += 2)
		mark[i] = true;

	for (i = 3; i <= limit; i += 2) {
		if (!mark[i]) {
			for (j = i * i; j < N; j += i * 2)
				mark[j] = true;
		}
	}

	for (i = 2; i < N; i++)
		if (!mark[i]) prime.push_back(i);
}

void pf(ll x, unordered_map <ll, ll> &mp) {
	for(ll z : prime) {
		if(z * z > x) break;
		
		while(x % z == 0) {
			x /= z;
			mp[z]++;
		}
	}
	if(x > 1) mp[x]++;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();

	int tc, t = 1;
	cin >> tc;

	while (tc--)
	{
		Case(t++);
		
		ll a, b, l;
		cin >> a >> b >> l;
		
		ll lcm = (a * b) / __gcd(a, b);
		if(l % lcm) {
			print("impossible");
			continue;
		}
		
		unordered_map <ll, ll> pfa, pfb, pfl;
		pf(a, pfa); pf(b, pfb); pf(l, pfl); 
		
		ll ans = 1;
		for(auto z : pfl) {
			ll x = z.ff, y = z.ss;
			if(pfa[x] >= y or pfb[x] >= y) y = 0;
			while(y--) ans *= x;
		}
		
		print(ans);
	}

	return 0;
}
