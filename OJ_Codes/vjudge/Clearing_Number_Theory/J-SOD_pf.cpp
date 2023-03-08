// Time: 2022-06-06 22:47:58	Problem: J - Efficient Pseudo Code 
// URL: https://vjudge.net/contest/498440#problem/J

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
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll N = 1e5 + 9, mod = 1e9 + 7;
bitset <N> mark;
vll prime;

void sieve() {
    mark[0] = mark[1] = 1;
    for(int i = 4; i < N; i += 2)
        mark[i] = 1;
    for(int i = 3; i * i <= N; i += 2)
        if(!mark[i])
            for(int j = i * i; j < N; j += 2 * i)
                mark[j] = 1;
                
    for(int i = 2; i < N; i++)
        if(!mark[i]) prime.pb(i);
}

vpll prime_factors(ll n) {
    vpll pf;
    for(ll &z : prime) {
        if(z * z > n) break;
        
        int c = 0;
        while(!(n % z)) {
            n /= z;
            c++;
        }
        if(c) pf.pb({z, c});
    }
    
    if(n != 1) pf.pb({n, 1});
    return pf;
}

ll bigmod(ll a, ll b) {
    if(!b) return 1;
    ll x = bigmod(a, b / 2);
    x = (x * x) % mod;
    if(b & 1) x = (x * a) % mod;
    return x; 
}

ll SOD(ll n, ll m) {
    vpll pf = prime_factors(n);
    
    ll sum = 1;
    for(auto &z : pf) {
        ll x = (bigmod(z.ff, z.ss * m + 1) - 1 + mod) % mod;
        x = (x * bigmod(z.ff - 1, mod - 2)) % mod; // pi^ai+1 - 1 / pi-1
        sum = (sum * x) % mod;
    }
    
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		ll n, m; cin >> n >> m;
		Case(cs++);
		print(SOD(n, m));
	}

	return 0;
}
