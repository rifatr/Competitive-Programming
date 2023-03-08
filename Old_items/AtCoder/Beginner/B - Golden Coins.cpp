#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll x, i, h, f500, f5;

    cin >> x;

    f500 = x / 500;
    x -= (500 * f500);

    f5 = x / 5;

    cout << f500 * 1000 + (f5 * 5) << endl;

    return 0;
}
