#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define scan(x) scanf("%d", &x)

ll inv(ll a, ll b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

const ll N = 2e6 + 7, mod = 1e9 + 7;
ll fact[N];

void factcal()
{
    fact[0] = 1;
    int i = 0;
    while (++i < N) fact[i] = (fact[i - 1] * i) % mod;
}

int main()
{
    factcal();

    int test, t = 1, n, k;

    scan(test);

    while (test--)
    {
        scan(n); scan(k);

        ll up = fact[n + k - 1];
        ll down = (fact[n] * fact[k - 1]) % mod;

        up = (up * inv(down, mod)) % mod;

        printf("Case %d: %lld\n", t++, up);
    }

    return 0;
}
