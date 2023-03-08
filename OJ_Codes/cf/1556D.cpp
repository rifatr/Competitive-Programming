// Problem: D. Take a Guess
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// Time: 2021-08-29 20:50:50
// URL: https://codeforces.com/contest/1556/problem/D


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
#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "\t", dbg(y);
#define dbg3(x, y, z) cout << #x << " = " << x << "\t", dbg2(y, z);
#define ddbg(x) cout << #x << " = [ "; for(auto z : x) cout << z << ' '; cout << "]\n";
#else
#define dbg(x)
#define adbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#define ddbg(x)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for(int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ':'\n');}

using namespace std;

inline ll askor(int i, int j) {
    cout << "or " << i << ' ' << j << endl;
    ll x;
    cin >> x;
    return x;
}
inline ll askan(int i, int j) {
    cout << "and " << i << ' ' << j << endl;
    ll x;
    cin >> x;
    return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	ll x = askor(1, 2) + askan(1, 2);
	ll y = askor(2, 3) + askan(2, 3);
	ll z = askor(1, 3) + askan(1, 3);

	ll ara[n];
	ara[0] = (z + x - y) / 2;
	ara[1] = x - ara[0];
	ara[2] = z - ara[0];

	for(int i = 4; i <= n; i++) {
        ll p = askor(1, i) + askan(1, i);
        ara[i - 1] = p - ara[0];
	}

	sort(ara, ara + n);
	cout << "finish " << ara[k - 1] << endl;

	return 0;
}
