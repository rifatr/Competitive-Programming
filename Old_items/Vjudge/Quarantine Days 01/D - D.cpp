#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long q, c, m, x, s;

    cin >> q;

    while(q--)
    {
        c = 0; m = 0; x = 0; s = 0;

        cin >> c >> m >> x;

        if(x == 0) {
            int sm = min(c, m);
            int bg = max(c, m);

            if(sm * 2 <= bg)
                cout << sm << endl;
            else
                cout << (c + m) / 3 << endl;

            continue;
        }

        if(c == m && m == x) {
            cout << c << endl;
            continue;
        }

        if(x > c || x > m) {
            cout << min(c, m) << endl;
            continue;
        }

        c -= x;
        m -= x;

        int sm = min(c, m);
        int bg = max(c, m);

        if(sm * 2 <= bg)
            s = sm;
        else
            s = (c + m) / 3;

        cout << s + x << endl;
    }

    return 0;
}
