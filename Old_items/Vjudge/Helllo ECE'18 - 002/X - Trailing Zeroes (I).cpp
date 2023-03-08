#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll total_divisor(ll x)
{
    ll i, c = 0, limit, divisors = 1, j;

    if(x % 2 == 0)
    {
        while(x % 2 == 0) {
            x /= 2;
            c++;
        }

        divisors *= (c + 1);
    }

    limit = sqrt(x * 1.0);
    for(j = 3; j <= limit; j += 2)
    {
        c = 1;

        while(x % j == 0) {
            x /= j;
            c++;
        }

        divisors *= c;
    }

    if(x > 2)
        divisors *= 2;

    return divisors;
}

int main()
{
    ll q, n, k;

    scanf("%lld", &q);

    for(k = 1; k <= q; k++)
    {
        scanf("%lld", &n);

        printf("Case %lld: %lld\n", k, total_divisor(n) - 1);
    }

    return 0;
}


