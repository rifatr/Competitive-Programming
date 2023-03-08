#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, x, p, t, n;

    cin >> n >> q;

    vector <ll> v[n + 1];

    while(q--)
    {
        cin >> x >> t;

        if(x == 0) {
            cin >> p;
            v[t].push_back(p);
        }

        else if(x == 1) {
            for(ll i = 0; i < v[t].size(); i++) {
                cout << v[t][i];
                if(i < v[t].size() - 1)
                    cout << " ";
            }
            cout << endl;
        }

        else {
            if(!v[t].empty())
                v[t].clear();
        }
    }

    return 0;
}

