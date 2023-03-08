#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, x, p;
    set <ll> S;

    cin >> q;

    while(q--)
    {
        cin >> x >> p;

        if(x == 0) {
            S.insert(p);
            cout << S.size() << endl;
        }

        else
        {
            S.find(p) == S.end() ? cout << 0 << endl : cout << 1 << endl;
        }
    }

    return 0;
}

