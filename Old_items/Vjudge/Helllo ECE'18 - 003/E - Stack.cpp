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

    stack <ll> st[n + 1];

    while(q--)
    {
        cin >> x >> t;

        if(x == 0) {
            cin >> p;
            st[t].push(p);
        }

        else if(x == 1) {
            if(!st[t].empty())
                cout << st[t].top() << endl;
        }

        else {
            if(!st[t].empty())
                st[t].pop();
        }
    }

    return 0;
}

