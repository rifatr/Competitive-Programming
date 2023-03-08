#include<bits/stdc++.h>
#define ll long long
#define N 1000007

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

int total_prime_factors(int x)
{
    int i, c = 0, limit, j = primes[0];

    if(mark[x] == false)
        return 1;

    for(i = 0; j * j <= x  && i < nP ; j++)
    {
        j = primes[i];

        if(x % j == 0) {
            c++;
            while(x % j == 0)
                x /= j;
        }
    }

    if(x != 1)
        c++;

    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

   // cout << np;

    int q, n, k, a, b, z, counter;

    scanf("%d", &q);

    for(k = 1; k <= q; k++)
    {
        scanf("%d %d %d", &a, &b, &n);

        counter = 0;
        for(z = a; z <= b; z++)
        {
            if(total_prime_factors(z) == n) {
                counter++;
            }
        }

        printf("%d\n", counter);
    }

    return 0;
}
