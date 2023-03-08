#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, x, p, d;
    deque <ll> v;

    cin >> q;

    while(q--)
    {
        cin >> p;

        if(p == 0) {
            cin >> d >> x;
            if(d == 1)
                v.push_back(x);
            else
                v.push_front(x);
        }

        else if(p == 1) {
            cin >> x;
            cout << v[x] << endl;
        }

        else {
            cin >> d;
            if(d == 1)
                v.pop_back();
            else
                v.pop_front();
        }
    }

    return 0;
}

