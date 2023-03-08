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

    cin >> n;

    pair <ll, ll> point[n];

    for(ll i = 0; i < n; i++)
        cin >> point[i].ff >> point[i].sc;

    sort(point, point + n);

    for(ll i = 0; i < n; i++)
        cout << point[i].ff << " " << point[i].sc << endl;

    return 0;
}
