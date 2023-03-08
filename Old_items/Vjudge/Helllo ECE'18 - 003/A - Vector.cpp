#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, x, p;
    vector <ll> v;

    cin >> q;

    while(q--)
    {
        cin >> x;

        if(x == 0) {
            cin >> p;
            v.push_back(p);
        }

        else if(x == 1) {
            cin >> p;
            cout << v[p] << endl;
        }

        else
            v.pop_back();
    }

    return 0;
}
