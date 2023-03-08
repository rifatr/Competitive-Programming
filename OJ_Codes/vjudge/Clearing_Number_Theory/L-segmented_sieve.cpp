// Time: 2022-06-05 15:30:36	Problem: L - Help Hanzo 
// URL: https://vjudge.net/contest/498440#problem/L

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

const int N = 1e5 + 9;
bitset <N> mark, mark2;
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

int segmented_sieve(ll l, ll r) {
    mark2.reset();
    
    for(ll z : prime) {
        if(z * z > r) break;
        
        ll j = ((l + z - 1) / z) * z; 
        if(j == z) j += z;
        for(; j <= r; j += z) {
            mark2[j - l] = 1;
            // dbg2(z, j)
        }
            
    }
    
    int ans = 0;
    for(int i = max(2ll, l); i <= r; i++) {
        ans += !mark2[i - l];
    }
        
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		ll l, r;
		cin >> l >> r;
		Case(cs++);
		print(segmented_sieve(l, r));
	}

	return 0;
}
