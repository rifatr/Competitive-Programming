#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, qq, i, j;

    cin >> n;

    int ar[n + 1], v[n + 1], p [n + 1];

    for(i = 1; i <= n; i++)
        cin >> ar[i];

    for(i = 1, j = n; i <= n; i++, j--)
    {
        v[ar[i]] = i;
        p[ar[j]] = i;
    }

    cin >> q;

    ll vs = 0, pt = 0;

    for(i = 1; i <= q; i++)
    {
        cin >> qq;

        vs += v[qq];
        pt += p[qq];
    }

    cout << vs << " " << pt << '\n';

    return 0;
}
