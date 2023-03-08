#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll facto(ll x)
{
    ll i = 1;
    for(int p = 1; p <= x; p++) {
        i *= p;
    }

    return i;
}

int main()
{
    ll tt, n, c = 1;
    string s;
    ll x[257];

    memset(x, 0, sizeof(x));

    cin >> s;

    n = s.size();

    for(ll i = 0; i < n; i++) {
        ll p = s[i];
        x[p % 257]++;
    }

    for(int i = 0; i < 257; i++)
        if(x[i] > 1)
            c *= facto(x[i]);

    ll res = facto(n) / c;

    cout << res << endl;

    return 0;
}
