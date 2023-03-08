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

    queue <ll> Q[n + 1];

    while(q--)
    {
        cin >> x >> t;

        if(x == 0) {
            cin >> p;
            Q[t].push(p);
        }

        else if(x == 1) {
            if(!Q[t].empty())
                cout << Q[t].front() << endl;
        }

        else {
            if(!Q[t].empty())
                Q[t].pop();
        }
    }

    return 0;
}


