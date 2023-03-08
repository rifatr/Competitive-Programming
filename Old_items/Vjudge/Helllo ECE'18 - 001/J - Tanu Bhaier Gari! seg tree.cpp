#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll trr[4000000];

void seg_build(ll ar[], ll pos, ll L, ll R)
{
    trr[pos] = 0;
    if(L == R)
    {
        trr[pos] = ar[L];
        return;
     }

     ll mid = (L + R) / 2;
     seg_build(ar, pos * 2, L, mid);
     seg_build(ar, pos * 2 + 1, mid + 1, R);
     trr[pos] = trr[pos * 2] + trr[pos * 2 + 1];
}

ll seg_query(ll pos, ll L, ll R, ll l, ll r)
{
    if(r < L || R < l)
        return 0;
    if(l <= L && R <= r)
        return trr[pos];

    ll mid = (L + R) / 2;
    ll x = seg_query(pos * 2, L, mid, l, r);
    ll y = seg_query(pos * 2 + 1, mid + 1, R, l, r);

    return x + y;
}
int main()
{
    int t;
    ll n, q, t1, t2, i, j, sum, k;

    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lld %lld", &n, &q);

        ll* cars = (ll*) calloc(n, sizeof(ll));
        for(j = 0; j < n; j++)
            scanf("%lld", &cars[j]);

        seg_build(cars, 1, 1, n);

        printf("Case %lld:\n", i);

        for(j = 0; j < q; j++) {
            scanf("%lld %lld", &t1, &t2);

            //sum = seg_query(1, 1, n, t1, t2);

            printf("%lld\n", seg_query(1, 1, n, --t1, --t2));
        }

        free(cars);
    }

    return 0;
}
