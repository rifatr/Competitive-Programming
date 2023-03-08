#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, x, p;
    list <ll> l;
    list <ll> :: iterator cursor = l.begin(), it;

    cin >> q;

    while(q--)
    {
        cin >> x;

        if(x == 0) {
            cin >> p;
            //cout << "inserted before " << *cursor << endl;
            l.insert(cursor, p);
            cursor--;
        }

        else if(x == 1) {
            cin >> p;
            if(p > 0) {
                for(int i = 0; i < p; i++)
                    cursor++;
            }
            else {
                p = abs(p);
                for(int i = 0; i < p; i++)
                    cursor--;
            }
        }

        else {
            it = cursor;
            //cout << "it = " << *it << endl;
            cursor++;
            //cout << "cursor = " << *cursor << endl;
            l.erase(it);
        }
    }

    for(it = l.begin(); it != l.end(); it++)
        cout << *it << endl;

    return 0;
}

