#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll bigmod(ll b, ll p, ll m)
{
    if(p == 0)
        return 1 % m;

    ll x = bigmod(b, p / 2, m);
    x = (x * x) % m;
    if(p % 2 != 0)
        x = (x * b) % m;

    return x;
}

int main()
{
    ll b, p, m, i, j;

    while(3 == scanf("%lld %lld %lld", &b, &p, &m))
    {
        cout << bigmod(b, p, m) << endl;
    }
}
