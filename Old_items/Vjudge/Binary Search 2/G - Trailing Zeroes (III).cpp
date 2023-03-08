#include<bits/stdc++.h>

using namespace std;

#define N 10000000000000000

long long facto_zero(long long x);

int main()
{
    long long tt, t = 1, n;

    cin >> tt;

    while(tt--)
    {
        cin >> n;

        long long lo = 1, hi = N, mid, x = -1, res;

        while(lo < hi and x != n)
        {
            mid = lo + ((hi - lo) / 2);

            x = facto_zero(mid);

            if(x > n)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        if(x == n)
        {
            res = mid % 5 == 0 ? mid : mid - (mid % 5);

            printf("Case %lld: %lld\n", t++, res);
        }

        else
            printf("Case %lld: impossible\n", t++);
    }

    return 0;
}

long long facto_zero(long long x)
{
    long long i = 5, n = 0;
    while(i <= x)
    {
        n += x / i;
        i *= 5;
    }

    return n;
}
