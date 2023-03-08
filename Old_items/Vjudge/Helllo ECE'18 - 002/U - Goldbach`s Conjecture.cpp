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

int conjecture(int n)
{
    int z = primes[0], c = 0, x;

    for(i = 0; z <= n / 2; i++)
    {
        z = primes[i];
        x = n - primes[i];

        if(!mark[x])
            c++;
    }

    return c;
}

int main()
{
    int t, n;

    scanf("%d", &t);

    for(int k = 1; k <= t; k++)
    {
        scanf("%d", &n);

        printf("Case %d: %d\n", k, conjecture(n));
    }

    return 0;
}
