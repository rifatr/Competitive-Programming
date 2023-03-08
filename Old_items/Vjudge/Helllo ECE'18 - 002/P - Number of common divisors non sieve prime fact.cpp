#include<bits/stdc++.h>
#define ll long long
#define N 1000009

using namespace std;

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

ll total_divisor(ll x)
{
    ll i, c = 1, divisors = 1;

   if(x % 2 == 0)
   {
       while(x % 2 == 0)
       {
           x /= 2;
           c++;
       }

       divisors *= c;
   }

   ll limit = sqrt(x * 1.0);

   for(ll j = 3; j <= limit; j += 2)
   {
       c = 1;

       while(x % j == 0)
       {
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

    ll t, a, b;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld %lld", &a, &b);

        ll x = gcd(a, b);

        printf("%lld\n", total_divisor(x));
    }

    return 0;
}

