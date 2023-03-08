#include<bits/stdc++.h>
#define ll long long
#define N 10000009

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
}

ll conjecture(ll n)
{
    ll z, c = 0, x, i;

    for(i = 0; ; i++)
    {
        z = primes[i];
        x = n - primes[i];

        if(z > n / 2)
            break;

        if(!mark[x]) {
            c++;
            //cout << z << " " << x << endl;
        }
    }

    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    ll t, n;

    scanf("%lld", &t);

    for(ll k = 1; k <= t; k++)
    {
        scanf("%lld", &n);

        printf("Case %lld: %lld\n", k, conjecture(n));
    }

    return 0;
}

