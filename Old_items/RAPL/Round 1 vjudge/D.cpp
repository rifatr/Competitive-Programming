#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    double r1, r2, d, dis, len;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    d = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    dis = max(r1, r2) - min(r1, r2);
    len =r1 + r2;

    if(x1 == x2 and y1 == y2 and r1 == r2) cout << -1 << endl;
    else if(d == len or d == dis) cout << 1 << endl;
    else if(d > len or d < dis) cout << 0 << endl;
    else cout << 2 << endl;

    return 0;
}
