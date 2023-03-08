#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, x, y;
    string p;
    map <string, ll> mp;

    cin >> q;

    while(q--)
    {
        cin >> x >> p;

        if(x == 0) {
            cin >> y;
            mp[p] = y;
        }

        else if(x == 1)
            cout << mp[p] << endl;

        else
            mp.erase(p);
    }

    return 0;
}



