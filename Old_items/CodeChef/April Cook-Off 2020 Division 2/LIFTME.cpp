#include<bits/stdc++.h>
#define N 1000003
#define ll long long

using namespace std;

int main()
{
    ll n, t, q, f, d, i, j;

    cin >> t;

    while(t--)
    {
        ll sum = 0, i, p = 0;

        cin >> n >> q;

        for(i = 1; i < q; i++) {
            cin >> f >> d;

            sum += abs(p - f);
            sum += abs(d - f);
            p = d;
        }

        cout << sum << endl;
    }

    return 0;
}
