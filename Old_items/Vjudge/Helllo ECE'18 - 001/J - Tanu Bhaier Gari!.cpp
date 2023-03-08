#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long n, q, t1, t2, i, j, sum, k;

    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lld %lld", &n, &q);

        long long gari[n];
        for(j = 0; j < n; j++) {
            scanf("%lld", &gari[j]);
            if(j > 0)
                gari[j] += gari[j - 1];
        }

        printf("Case %lld:\n", i);

        for(j = 0; j < q; j++) {
            scanf("%lld %lld", &t1, &t2);
            t1--;
            t2--;

            if(t1 > 0)
                printf("%lld\n", gari[t2] - gari[t1 - 1]);
            else
                printf("%lld\n", gari[t2]);
        }

    }

    return 0;
}
