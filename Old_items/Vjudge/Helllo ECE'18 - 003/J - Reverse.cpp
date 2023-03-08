#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll b, e, i, in, n, q;
    vector <ll> v;

    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> in;
        v.push_back(in);
    }

    cin >> q;
    while(q--)
    {
        cin >> b >> e;

        reverse(&v[b], &v[e]);
    }

    for(i = 0; i < n; i++) {
        cout << v[i];
        if(i < n - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}

