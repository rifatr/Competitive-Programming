// Time: 2022-06-09 00:56:34	Problem: K - LCM from 1 to n 
// URL: https://vjudge.net/contest/498440#problem/K

#include <bits/stdc++.h>

#define ll unsigned long long
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

#define ui unsigned int

const int N = 1e8 + 10;
bitset <N> mark;
vector <int> prime;
ui premul[7 * N / 100];

void sieve() {
    for(int i = 3; i * i < N; i += 2) 
        if(!mark[i])
            for(int j = i * i; j < N; j+= 2 * i)
                mark[j] = 1;
    
    prime.pb(2);
    for(ui i = 3; i < N; i += 2)
        if(!mark[(int)i]) prime.pb(i);
        
    premul[0] = 2;
    for(ui i = 1; i < prime.size(); i++)
        premul[i] = premul[i - 1] * prime[i];
}

ui bigmod(ui a, ui b) {
    ui res = 1;
    while(b > 0) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		ui n; cin >> n;
		
		int lim = sqrt(n) + 1;
		int l = lower_bound(all(prime), lim) - prime.begin();
		int r = upper_bound(all(prime), n) - prime.begin(); r--;
		
		ui res = premul[r];
		for(int i = 0; i < l; i++) {
		    int c = 0;
		    ll a = prime[i];
		    while(a <= n) a *= prime[i], c++;
		    
		    lopj(c - 1) res *= prime[i];
		}
		
		Case(cs++); print(res);
	}

	return 0;
}

// log_b (c) = log_a (c) / log_a (b)
