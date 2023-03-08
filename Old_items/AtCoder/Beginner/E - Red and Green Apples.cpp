#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll x, y, p, q, r, i, inp;
    vector <ll> a, b, c;

    cin >> x >> y >> p >> q >> r;

    for(i = 0; i < p; i++)
    {
        cin >> inp;
        a.push_back(inp);
    }
    for(i = 0; i < q; i++)
    {
        cin >> inp;
        b.push_back(inp);
    }
    for(i = 0; i < r; i++)
    {
        cin >> inp;
        c.push_back(inp);
    }

    sort(a.begin(), a.end(), greater <ll> ());
    sort(b.begin(), b.end(), greater <ll> ());

    for(i = 0; i < x; i++)
    {
        c.push_back(a[i]);
    }
    for(i = 0; i < y; i++)
    {
        c.push_back(b[i]);
    }

    sort(c.begin(), c.end(), greater <ll> ());

    ll sum = 0;

    for(i = 0; i < x + y; i++)
        sum += c[i];

    cout << sum << endl;

    return 0;
}
