#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll mod = 1e9 + 7, N = 1e6 + 8;

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

	for (int i = 2; i < N; i++)
		if (!mark[i]) prime.push_back(i);
}

void phi_sieve()
{
	bool mark[N + 1] = {0};
	int phi[N];
	for (int i = 0; i < N; i++)
		phi[i] = i;

	mark[1] = true;
	for (int i = 2; i <= N; i += 2) {
		if (!mark[i]) {
			for (int j = i; j <= N; j += i) {
				mark[j] = true;
				phi[j] = (phi[j]  / i) * (i - 1);
			}
		}
	}
}

int phi(int n)
{
	int ph = n;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;

		while (n % i == 0)
			n /= i;

		ph -= ph / i; //ph * (1 - 1/p)
	}

	if (n > 1)
		ph -= ph / n;

	return ph;
}

ll ncr(ll n, ll r)
{
	if (r > n)
		return 0;

	if (r > n - r)
		r = n - r;

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

int main()
{
	return 0;
}
