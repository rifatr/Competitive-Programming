// Time: 2022-08-26 17:41:38	Problem: E. Forming Teams 
// URL: https://algo.codemarshal.org/contests/ncpc-uap-2016/problems/E

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll N = 1e6 + 10, mod = 1e9 + 7;

ll bigmod(ll a, ll b) {
	if (!b) return 1;

	ll x = bigmod(a, b / 2);
	x = ((x % mod) * (x % mod)) % mod;

	if (b & 1) x = ((x % mod) * (a % mod)) % mod;
	return x;
}

// return (1 / a) % b. multiply this with ans.
ll inverse_mod(ll a, ll b) {
	return 1 < a ? b - inverse_mod(b % a, a) * b / a : 1;
}

ll fact[N]; //factorial of first N numbers
void factorial() {
	fact[0] = 1;
	for (ll i = 1; i < N; i++)
		fact[i] = (fact[i - 1] * i) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	factorial();

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		ll n, ans = 0;
		cin >> n;
		
		auto cal = [] (ll r) {
		    ll sum = fact[n];
		    ll x = (bigmod(fact[r], n / r) * fact[n / r]) % mod;
		    sum = (sum * inverse_mod(x, mod)) % mod;
		    return sum;
		};
		
		for(ll i = 1; i * i <= n; i++) {
		    if(n % i != 0) continue;
		    ll j = n / i;
		    
		    ans += cal(i);
		    if(i != j) ans += cal(j); 
		    ans %= mod;
		}
		
		Case(cs++);
		print(ans);
	}

	return 0;
}
