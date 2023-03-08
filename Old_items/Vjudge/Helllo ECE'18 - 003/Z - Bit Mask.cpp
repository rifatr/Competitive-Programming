#include<bits/stdc++.h>

#define ll long long

using namespace std;

bool bit[64];

int main()
{
    ll n, i, q, k, j, m;
    //bitset <64> bit;

    cin >> n;

    vector <int> mask[n + 1];

    for(i = 0; i < n; i++)
    {
        cin >> k;
        for(j = 0; j < k; j++) {
            cin >> q;
            mask[i].push_back(q);
        }
    }

    cin >> q;
    while(q--)
    {
        cin >> k >> m;

        if(k == 0)
        {
            cout << bit[m] << endl;
        }
        else if(k == 1)
        {
            for(i = 0; i < mask[m].size(); i++)
                bit[mask[m][i]] = 1;
        }
        else if(k == 2)
        {
            for(i = 0; i < mask[m].size(); i++)
                bit[mask[m][i]] = 0;
        }
        else if(k == 3)
        {
            for(i = 0; i < mask[m].size(); i++)
                bit[mask[m][i]] = 1 - bit[mask[m][i]];
        }
        else if(k == 4)
        {
            bool flag = true;
            for(i = 0; i < mask[m].size(); i++)
                if(bit[mask[m][i]] == 0)
                    flag = false;

            cout << flag << endl;
        }
        else if(k == 5)
        {
            bool flag = false;
            for(i = 0; i < mask[m].size(); i++)
                if(bit[mask[m][i]] == 1)
                    flag = true;

            cout << flag << endl;
        }
        else if(k == 6)
        {
            bool flag = true;
            for(i = 0; i < mask[m].size(); i++)
                if(bit[mask[m][i]] == 1)
                    flag = false;

            cout << flag << endl;
        }
        else if(k == 7)
        {
            int c = 0;
            for(i = 0; i < mask[m].size(); i++)
                if(bit[mask[m][i]] == 1)
                    c++;

            cout << c << endl;
        }
        else if(k == 8)
        {
            bitset <64> bm;
            for(i = 0; i < mask[m].size(); i++)
                bm.set(mask[m][i]);

            cout << bm.to_ulong() << endl;
            cout << bm << endl;
        }
    }

    return 0;
}

