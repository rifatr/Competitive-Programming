#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, i;

    cin >> n;
    ll a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    ll b[m];
    for(i = 0; i < m; i++)
        cin >> b[i];

    cout << includes(a, a + n, b, b + m) << endl;

    return 0;
}
