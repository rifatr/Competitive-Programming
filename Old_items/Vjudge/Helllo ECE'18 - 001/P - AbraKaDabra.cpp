#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k, a, b, l, x, y, i, z;
    string s, p;

    cin >> k >> a >> b;
    cin.ignore();
    cin >> s;
    l = s.size();

    x = l / k;
    z = l % k;

    if(ceil(l / (k * 1.0)) > b || x < a) {
        cout << "No solution\n";
        return 0;
    }

    y = 0;

    for(i = 0; i < k; i++)
    {
        if(z > 0) {
            p.assign(s, y, min(x + 1, l - y));
            z--;
            y += x + 1;
        }
        else {
            p.assign(s, y, min(x, (l - y)));
            y += x;
        }
        cout << p << endl;
    }

    return 0;
}
