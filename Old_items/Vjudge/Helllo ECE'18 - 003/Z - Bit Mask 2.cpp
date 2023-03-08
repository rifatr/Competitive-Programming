#include<bits/stdc++.h>

#define ll long long

using namespace std;


int main()
{
    ll n, i, q, k, j, m;
    bitset <64> bit;

    cin >> n;

    bitset <64> mask[n];

    for(i = 0; i < n; i++)
    {
        cin >> k;
        for(j = 0; j < k; j++) {
            cin >> q;
            mask[i].set(q);
        }
    }

    cin >> q;
    while(q--)
    {
        cin >> k >> m;

        if(k == 0)
        {
            cout << bit.test(m) << endl;
        }
        else if(k == 1)
        {
            bit |= mask[m];
        }
        else if(k == 2)
        {
            bit &= ~mask[m];
        }
        else if(k == 3)
        {
            bit ^= mask[m];
        }
        else if(k == 4)
        {
            cout << ((bit & mask[m]) == mask[m]) << endl;
        }
        else if(k == 5)
        {
            cout << (bit & mask[m]).any() << endl;
        }
        else if(k == 6)
        {
            cout << (bit & mask[m]).none() << endl;
        }
        else if(k == 7)
        {
            cout << (bit & mask[m]).count() << endl;
        }
        else if(k == 8)
        {
            cout << (bit & mask[m]).to_ulong() << endl;
            //cout << (bit & mask[m]) << endl;
        }
    }

    return 0;
}

