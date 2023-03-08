#include<bits/stdc++.h>

#define ll long long
#define ff first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x, y;
    ll v, w, d;
    char t;
    string s;

    cin >> n;

    tuple <ll, ll, char, ll, string> items[n];

    for(ll i = 0; i < n; i++) {
        cin >> v >> w >> t >> d >> s;
        items[i] = make_tuple(v, w, t, d, s);
    }

    sort(items, items + n);

    for(ll i = 0; i < n; i++) {
        cout << get<0>(items[i]) << " " << get<1>(items[i]) << " " << get<2>(items[i])
            << " " << get<3>(items[i]) << " " << get<4>(items[i]) << "\n";
    }

    return 0;
}

