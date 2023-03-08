#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, x, y;
    string p, o;
    multimap <string, ll> mp;

    cin >> q;

    while(q--)
    {
        cin >> x >> p;

        if(x == 0)
        {
            cin >> y;
            mp.insert(pair <string, ll> (p, y));
        }

        else if(x == 1)
        {
            auto it3 = mp.equal_range(p);
            auto it = it3.first;
            auto it2 = it3.second;
            if(it == mp.end())
                continue;
            while(it != it2)
            {
                cout << it -> second << endl;
                it++;
            }
        }

        else if(x == 2)
        {
            mp.erase(p);
        }

        else
        {
            cin >> o;
            auto it = mp.lower_bound(p);
            auto it2 = mp.upper_bound(o);

            for(; it != it2; it++)
                cout << it -> first << " " << it -> second << endl;
        }
    }

    return 0;
}




