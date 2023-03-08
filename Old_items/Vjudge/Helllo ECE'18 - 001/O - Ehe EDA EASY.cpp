#include<bits/stdc++.h>
#define ll long long

using namespace std;

void OJ()
{
    freopen("O in.txt", "r", stdin);
    freopen("O out.txt", "w", stdout);
}


ll facto_zero(ll n)
{
    int j, z = 0;

    for(j = 5; j <= n; j *= 5)
        z += (n / j);

    return z;
}
int main()
{
    //OJ();

    ll n, t, q, i, j, p, z;

    cin >> t;

    for(i = 1; i <= t; i++)
    {
        cin >> q;

        ll lo = 1, hi = 1000000001, mid;

        while(1)
        {
            mid = lo + ((hi - lo)/ 2);
            p = facto_zero(mid);

//            cout << "lo = " << lo << "hi = " << hi << endl;
           // cout << mid << "\t" << p << endl;

            if(q == p)
                break;
            else if(p < q)
                lo = mid + 1;
            else if(p > q)
                hi = mid - 1;

            if(lo >= hi)
                break;
        }

        if(p == q)
        {
            if(mid % 5 == 0)
                z = mid;
            else
                z = mid - (mid % 5);

            printf("Case %lld: %lld\n", i, z);
        }
        else
            printf("Case %lld: impossible\n", i);
    }

    return 0;
}
