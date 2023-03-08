#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define sc(a) scanf("%lld", &a)
#define pt(a) printf("%lld", a)
#define psp printf(" ")
#define pnl printf("\n")

ll sumd(ll a)
{
    ll s = 0;

    while(a)
    {
        s += a % 10;
        a /= 10;
    }

    return s;
}

int main()
{
    ll tt;

    sc(tt);

    while(tt--)
    {
        ll rnd, a, b, pc, pm;
        pc = pm = 0;

        sc(rnd);

        while(rnd--)
        {
            sc(a); sc(b);

            a = sumd(a);
            b = sumd(b);

            if(a > b) pc++;
            else if (a < b) pm++;
            else {
                pc++;
                pm++;
            }

            //cout << a << " " << b << " " << pc << " " << pm << endl;
        }

        if(pc > pm) pt(0LL);
        else if (pc < pm) pt(1LL);
        else pt(2LL);

        psp;
        pc > pm ? pt(pc) : pt(pm);
        pnl;
    }

    return 0;
}
