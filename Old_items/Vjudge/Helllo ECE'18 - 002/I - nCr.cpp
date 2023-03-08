#include<bits/stdc++.h>
#define ll unsigned long long
#define mod 142857

using namespace std;

ll nCr_mod(ll n, ll r)
{
    ll m = max(r, n - r), s = min(r, n - r), i;

    ll fct_n = 1, fct_s = 1, nCr;

    for(i = n; i > m; i--)
        fct_n = ((fct_n % mod) * (i % mod)) % mod;

    for(i = s; i > 1; i--)
        fct_s = ((fct_s % mod) * (i % mod)) % mod;

    nCr = fct_n / fct_s;

    return nCr;
}

int main()
{
//    nfacto();

    ll t, n, r, res;

    cin >> t;

    while(t--)
    {
        cin >> n >> r;

        cout << nCr_mod(n, r) << endl;
    }
}

