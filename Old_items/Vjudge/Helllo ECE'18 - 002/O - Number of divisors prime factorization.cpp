#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q, n, i, c, limit, divisors, x, j;

    scanf("%lld", &q);

    while(q--)
    {
        scanf("%lld", &n);

        x = n;

        c = 0;
        divisors = 1;
        if(x % 2 == 0)
        {
            while(x % 2 == 0) {
                x /= 2;
                c++;
            }

            divisors *= (c + 1);
        }

        int limit = sqrt(x * 1.0);
        for(j = 3; j <= limit; j += 2)
        {
            c = 0;
            if(x % j == 0) {
                while(x % j == 0) {
                    x /= j;
                    c++;
                }
                divisors *= (c + 1);
            }
        }

        if(x > 2)
            divisors *= 2;

        printf("%lld\n", divisors);
    }

    return 0;
}
