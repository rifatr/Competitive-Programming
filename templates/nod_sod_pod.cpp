// Time: 2022-11-30 19:42:46	Problem: G - Divisor Analysis 
// URL: https://vjudge.net/contest/531223#problem/G

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
#define loop(i, a, b) for (int i = a; i < b; i++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifdef rifat
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
// sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

ll bigmod(ll a, ll b, ll mod) {
	if (!b) return 1;

	ll x = bigmod(a, b / 2, mod);
	x = ((x % mod) * (x % mod)) % mod;

	if (b & 1) x = ((x % mod) * (a % mod)) % mod;
	return x;
}

const ll N = 1e5 + 20, mod = 1e9 + 7, phi = mod - 1;
ll n, p[N], a[N], b[N], mult[N], pre[N], post[N];

void rfs() {
    pre[0] = a[0] + 1;
    lop(n - 1) pre[i + 1] = (pre[i] * (a[i + 1] + 1)) % phi;
    
    post[n - 1] = a[n - 1] + 1;
    for(int i = n - 2; i >= 0; i--)
        post[i] = (post[i + 1] * (a[i] + 1)) % phi;
        
    loop(i, 1, n - 1) mult[i] = (pre[i - 1] * post[i + 1]) % phi;
    mult[0] = post[1]; mult[n - 1] = pre[n - 2];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	cin >> n;
	lop(n) cin >> p[i] >> a[i];
	
	if(n == 1) {
	    n++;
	    p[1] = p[0];
	    a[1] = 0;
	}
	
	// number of divisors (nod)
	ll nod = 1;
	lop(n) nod = (nod * (a[i] + 1)) % mod;
	cout << nod << ' ';
	
	// sum of divisors (sod)
	ll sod = 1;
	lop(n) {
	    ll x = (bigmod(p[i], a[i] + 1, mod) - 1 + mod) % mod;
		x = (x * bigmod(p[i] - 1, mod - 2, mod)) % mod; // pi^ai+1 - 1 / pi-1
		sod = (sod * x) % mod;
	}
	cout << sod << ' ';
	
	// product of divisors (pod)
	ll pod = 1; 
	rfs();
	// print(mult, n);
	
	lop(n) {
	    ll x = (((a[i] + 1) * a[i]) / 2) % phi;
	    b[i] = (x * mult[i]) % phi;
	}
	lop(n) pod = (pod * bigmod(p[i], b[i], mod)) % mod;
	cout << pod << '\n';

	return 0;
}
