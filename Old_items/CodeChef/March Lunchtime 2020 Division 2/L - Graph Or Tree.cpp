#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, inp, x, y, f = 0, c = 0;
    vector <int> u, v;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> x >> y;

        u.push_back(x);
        v.push_back(y);

        c = count(u.begin(), u.end(), y);
        if(c > 0)
            f++;
    }

    if(f == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
