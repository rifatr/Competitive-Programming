#include<bits/stdc++.h>
#define ll long long
#define N 100000009

using namespace std;

bool mark[N + 1];
ll nP;
vector <ll> primes;

void sieve()
{
    ll i, j, limit = sqrt(N * 1.0);

    mark[0] = mark[1] = true;

    primes.push_back(2);

    for(i = 4; i <= N; i += 2)
        mark[i] = true;

    for(i = 3; i <= limit; i += 2)
    {
        if(mark[i] == false)
        {
            for(j = i * i; j <= N; j += (i * 2))
                mark[j] = true;
        }
    }

    for(i = 3; i <= N; i += 2)
    {
        if(!mark[i]) {
            primes.push_back(i);
        }
    }

    nP = primes.size();

    return;
}

ll total_divisor(ll x)
{
    ll i, c, divisors = 1, j = primes[0];

    for(i = 0; j * j <= x && i < nP; i++)
    {
        j = primes[i];
        c = 1;

        while(x % j == 0) {
            x /= j;
            c++;
        }

        divisors *= c;
    }

    if(x != 1)
        divisors *= 2;

    return divisors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    ll q, n, k;

    scanf("%lld", &q);

    for(k = 1; k <= q; k++)
    {
        scanf("%lld", &n);

        printf("%lld\n", total_divisor(n));
    }

    return 0;
}

