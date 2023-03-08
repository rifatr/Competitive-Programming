#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll mod = 1e9 + 7, N = 1e6 + 8;

bitset <N> mark;
vector <int> prime;
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

// return number of primes in a range [l, r]; r-l <= 1e5
bitset <N> mark2;
int segmented_sieve(ll l, ll r) {
	mark2.reset();

	for (ll z : prime) {
		if (z * z > r) break;

		ll j = ((l + z - 1) / z) * z;
		if (j == z) j += z;
		for (; j <= r; j += z) {
			mark2[j - l] = 1;
			// dbg2(z, j)
		}

	}

	int ans = 0;
	for (int i = max(2ll, l); i <= r; i++) {
		ans += !mark2[i - l];
	}

	return ans;
}

vector <pair<int, int>> prime_factors(int n) {
	vector <pair<int, int>> pf;
	for (int &z : prime) {
		if (z * z > n) break;

		int c = 0;
		while (!(n % z)) {
			n /= z;
			c++;
		}
		if (c) pf.push_back({z, c});
	}

	if (n != 1) pf.push_back({n, 1});
	return pf;
}

ll bigmod(ll a, ll b) {
	if (!b) return 1;
	ll x = bigmod(a, b / 2);
	x = (x * x) % mod;
	if (b & 1) x = (x * a) % mod;
	return x;
}

ll SOD(int n) {
	vector <pair<int, int>> pf = prime_factors(n);

	ll sum = 1;
	for (auto &z : pf) {
		ll x = (bigmod(z.first, z.second + 1) - 1 + mod) % mod;
		x = (x * bigmod(z.first - 1, mod - 2)) % mod; // pi^ai+1 - 1 / pi-1
		sum = (sum * x) % mod;
	}

	return sum;
}

//inclusion-exclusion returns number of multiples of divs in [l, r]
ll iep(int l, int r, vector <int> &divs) {
	if (l > r) return 0;

	ll sum = 0, sz = divs.size();
	for (ll j = 1; j < (1LL << sz); j++) {
		ll gun = 1, one = 0;
		for (ll i = 0; i < sz; i++)
			if (j & (1LL << i)) {
				one++;
				gun *= divs[i];
			}

		ll naw = (r / gun) - ((l - 1) / gun);
		if (one % 2 == 1)
			sum += naw;
		else
			sum -= naw;
	}

	return sum;
}

// bitset <N+1> mark;
int phi[N];
void phi_sieve()
{
	for (int i = 0; i < N; i++)
		phi[i] = i;

	mark[1] = true;
	for (int i = 2; i < N; i++) {
		if (!mark[i]) {
			for (int j = i; j < N; j += i) {
				mark[j] = true;
				phi[j] = (phi[j]  / i) * (i - 1);
			}
		}
	}
}

int Phi(int n)
{
	if(n == 1) return 0;
	
	int ph = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;

		while (n % i == 0)
			n /= i;

		ph -= ph / i; //ph * (1 - 1/p)
	}

	if (n > 1) ph -= ph / n;
	return ph;
}

ll ncr(ll n, ll r)
{
	if (r > n) return 0;
	if (r > n - r) r = n - r;

	ll ans = 1;
	for (ll i = 1; i <= r; i++)
	{
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}

ll fibo(ll n)
{
	ll a = 0, b = 1, c = b;
	for (int i = 0; i < n - 1; i++)
	{
		c = (a + b) % mod;
		a = b % mod;
		b = c % mod;
	}

	return c;
}

ll power(ll a, ll b) {
	if (!b) return 1;
	if (b & 1) return a * power(a, b - 1);

	ll temp = power(a, b / 2);
	return temp * temp;
}

ll bigmod(ll a, ll b, ll mod) {
	if (!b) return 1;

	ll x = bigmod(a, b / 2, mod);
	x = ((x % mod) * (x % mod)) % mod;

	if (b & 1) x = ((x % mod) * (a % mod)) % mod;
	return x;
}

// return (1 / a) % b. multiply this with ans.
ll inverse_mod(ll a, ll b) {
	return 1 < a ? b - inverse_mod(b % a, a) * b / a : 1;
}

ll inv[N]; //inverse modulo pre calcaulate
void imod()
{
	inv[1] = 1;
	for (ll i = 2; i < N; i++)
		inv[i] = (mod - (mod / i) * inv[mod % i]) % mod;
}
// another way to find inverse modulo of n is bigmod(n, mod - 2, mod);

ll fact[N]; //factorial of first N numbers
void factorial() {
	fact[0] = 1;
	for (ll i = 1; i < N; i++)
		fact[i] = (fact[i - 1] * i) % mod;
}

ll nCr(ll n, ll r) {
	if (r > n) return 0;
	return (fact[n] * inverse_mod((fact[r] * fact[n - r]) % mod, mod)) % mod; // n! / r!*(n-r)!
}

ll nPr(ll n, ll r) {
	if (r > n) return 0;
	return (fact[n] * inverse_mod(fact[n - r], mod)) % mod; // n! / (n - r)!
}

// r-th value of n-th line of pascal triangle = nCr

int main()
{
	return 0;
}
