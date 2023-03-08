// Problem: Odd Numbers of Divisors
// Contest: Virtual Judge - SPOJ
// URL: https://vjudge.net/problem/SPOJ-ODDDIV
// Time: 2021-11-01 21:34:03

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

const ll N = 1e5 + 8;

bitset <N> mark;
vector <ll> prime, K[N];
int divs[N];

void sieve()
{
	mark[0] = mark[1] = true;
	for (int i = 4; i <= N; i += 2)
		mark[i] = true;

	for (int i = 3; i * i < N; i += 2) {
		if (!mark[i]) {
			for (int j = i * i; j < N; j += i * 2)
				mark[j] = true;
		}
	}

	for (int i = 2; i < N; i++)
		if (!mark[i]) prime.push_back(i);
}

int nod(ll n) {
	int c = 1;
	for(ll z : prime) {
		if(z * z > n) break;
		
		if(n % z == 0) {
			int k = 0;
			while(n % z == 0) {
				n /= z;
				k++;
			}
			
			c *= ++k;
		}
	}
	
	return c + (n > 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	sieve();
	for(ll i = 1; i < N - 4; i++) K[nod(i * i)].pb(i * i);

	int tc;
	cin >> tc;

	while (tc--)
	{
		ll l, r, k;
		cin >> k >> l >> r;
		
		int x = lower_bound(all(K[k]), l) - K[k].begin();
		if(x == K[k].size() or K[k][x] > r) {
			print(0);
			continue;
		}
		int y = upper_bound(all(K[k]), r) - K[k].begin();
		y--;
		if(y < x or K[k][y] < l) {
			print(0);
			continue;
		}
		
		print(y - x + 1);		
	}

	return 0;
}
