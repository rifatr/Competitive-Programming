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

    priority_queue <ll> PQ[n + 1];

    while(q--)
    {
        cin >> x >> t;

        if(x == 0) {
            cin >> p;
            PQ[t].push(p);
        }

        else if(x == 1) {
            if(!PQ[t].empty())
                cout << PQ[t].top() << endl;
        }

        else {
            if(!PQ[t].empty())
                PQ[t].pop();
        }
    }

    return 0;
}



