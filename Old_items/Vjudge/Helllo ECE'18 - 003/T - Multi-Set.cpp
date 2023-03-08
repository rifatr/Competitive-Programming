#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    ll q, x, p, o;
    multiset <ll> ms;

    cin >> q;

    while(q--)
    {
        cin >> x >> p;

        if(x == 0)
        {
            ms.insert(p);
            cout << ms.size() << endl;
        }

        else if(x == 1)
            cout << ms.count(p) << endl;

        else if(x == 2)
            ms.erase(p);

        else
        {
            cin >> o;
            auto it = ms.lower_bound(p);

            for(; it != ms.end() && *it <= o; it++)
                cout << *it << endl;
        }

    }

    return 0;
}
