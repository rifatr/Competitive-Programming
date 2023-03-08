#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll bigmod(ll a, ll b, ll m)
{
	if (b == 0)
		return 1;

	ll x = bigmod(a, b / 2, m);

	x = (x * x) % mod;

	if (b % 2)
		x = (x * a) % mod;

	return x;
}

int main()
{
	ll n;
	cin >> n;

	cout << bigmod(2, n, mod);
}