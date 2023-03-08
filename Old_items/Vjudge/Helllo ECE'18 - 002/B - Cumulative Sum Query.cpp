#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, q, i, l, r;

    cin >> n;

    ll arr[n];

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i > 0)
            arr[i] += arr[i - 1];
    }

    cin >> q;

    while(q--)
    {
        cin >> l >> r;

        if(l == 0)
            cout << arr[r] << endl;
        else
            cout << arr[r] - arr[l - 1] << endl;
    }

    return 0;
}
