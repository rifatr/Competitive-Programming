#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, j;
    unsigned long long int l, r;

    scanf("%d", &t);

    for( j = 1; j <= t; j++)
    {
        scanf("%llu %llu", &l, &r);
        if(l % 2 == 0)
            l++;

        n = ((r - l) / 2) + 1;

        printf("Case %d: %llu\n", j, n * (2 * l + (n - 1) * 2) / 2);
    }

    return 0;
}
