
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q, x;

    cin >> n;

    ll a[n + 1];
    a[0] = 0;

    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    cin >> q;

    for(ll i = 1; i <= q; i++) {
        cin >> x;

        cout << lower_bound(a, a + n + 1, x) - a << endl;
    }

    return 0;
}
