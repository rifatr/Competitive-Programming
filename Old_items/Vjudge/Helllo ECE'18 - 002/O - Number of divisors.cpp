#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll q, n, i, c, limit;

    scanf("%lld", &q);

    while(q--)
    {
        scanf("%lld", &n);

        c = 0;
        limit = sqrt(n);

        for(i = 1; i <= limit; i++)
        {
            if(n % i == 0)
            {
                if(i * i == n)
                    c++;
                else
                    c += 2;
            }
        }

        printf("%lld\n", c);
    }

    return 0;
}

