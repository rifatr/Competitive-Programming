#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    ll q, x, p, o;
    set <ll> S;

    cin >> q;

    while(q--)
    {
        cin >> x >> p;

        if(x == 0)
        {
            S.insert(p);
            cout << S.size() << endl;
        }

        else if(x == 1)
            cout << (S.find(p) != S.end() ? 1 : 0) << endl;

        else if(x == 2)
            S.erase(p);

        else
        {
            cin >> o;
            auto it = S.lower_bound(p);

            for(; it != S.end() && *it <= o; it++)
                cout << *it << endl;
        }

    }

    return 0;
}



