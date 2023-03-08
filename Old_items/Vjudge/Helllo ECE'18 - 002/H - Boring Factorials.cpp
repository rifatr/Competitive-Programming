#include<bits/stdc++.h>
#define pb push_back
#define ll unsigned long long

using namespace std;

vector <ll> factorials;
ll v;

ll facto_mod(ll n, ll p)
{
    if(n == 1)
        return 1 % p;

    ll x = 1 % p, z = n;

    if(n >= v) {
        x = ((n % p) * (facto_mod(n - 1, p) % p) % p);
        factorials.pb(x);
        v++;
    }

    cout << n << " * " << n - 1 << "! = " << factorials[n] << endl;

    return factorials[n];
}

int main()
{
    factorials.pb(1);
    factorials.pb(1);
    v = 2;

    ll t, n, p, res;

    cin >> t;

    while(t--)
    {
        cin >> n >> p;

        cout << facto_mod(n, p) << endl;
    }
}
