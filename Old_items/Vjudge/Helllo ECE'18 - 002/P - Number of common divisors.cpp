#include<bits/stdc++.h>
#define ll long long
#define N 1000009

using namespace std;

ll divisors[N];

void divisor_sieve()
{
    ll i, j;

    for(i = 1; i < N; i++)
    {
        for(j = i; j < N; j += i)
            divisors[j]++;
    }
}

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    divisor_sieve();

    ll t, a, b;

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        ll x = gcd(a, b);

        cout << divisors[x] << endl;
    }

    return 0;
}
