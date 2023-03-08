#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll k, n, i, dis, maxa = 0;

    cin >> k >> n;

    ll house[n];

    for(i = 0; i < n; i++)
    {
        cin >> house[i];
        if(i > 0) {
            dis = house[i] - house[i - 1];
            maxa = dis > maxa ? dis : maxa;
        }
    }

    dis = house[0] + k - house[n - 1];

    cout << k - max(dis, maxa) << endl;

    return 0;
}
