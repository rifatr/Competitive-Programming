#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll q, n, i, sum, limit;

    scanf("%lld", &q);

    while(q--)
    {
        scanf("%lld", &n);

        if(n == 1) {
            printf("0\n");
            continue;
        }

        sum = 1;
        limit = sqrt(n);

        for(i = 2; i <= limit; i++)
        {
            if(n % i == 0)
            {
                if(i * i == n)
                    sum += i;
                else {
                    sum += i;
                    sum += (n / i);
                }
            }
        }

        printf("%lld\n", sum);
    }

    return 0;
}
