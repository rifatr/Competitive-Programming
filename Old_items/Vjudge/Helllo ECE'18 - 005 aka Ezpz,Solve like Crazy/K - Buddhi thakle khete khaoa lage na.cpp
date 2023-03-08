#include<bits/stdc++.h>

#define ll long long
#define lop(n) for(ll i = 0; i < n; i++)

using namespace std;

int main()
{
    ll n, m, a, q, sum = 0;

    cin >> n;

    ll bar[n];

    lop(n) {
        cin >> bar[i];
        sum += bar[i];
    }

    sort(bar, bar + n, greater <ll> ());

    cin >> q;

    lop(q)
    {
        cin >> a;

        cout << sum - bar[a - 1] << '\n';
    }

    return 0;
}
