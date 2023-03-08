#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, i, x, z = 0;
    vector <int> p;

    for(i = 0; i < 4; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    cin >> h;

    sort(p.begin(), p.end());

    for(i = 1; i < 4; i++)
    {
        z += p[i];
    }

    if(z >= h)
        cout << "WAW\n";
    else
        cout << "AWW\n";

    return 0;
}
