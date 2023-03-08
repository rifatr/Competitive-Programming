#include<bits/stdc++.h>

#define pi 2 * acos(0.0)

using namespace std;

int main()
{
    int t;
    double n, l, area, x, theta, k, angle, lombo;
    cin >> t;

    while(t--)
    {
        cin >> l >> n;
        x = l / n;
        k = x / 2;

        theta = (2 * pi) / n;
        angle = (pi - theta) / 2;
        lombo = k * tan(angle);
        area = n * k * lombo;

        cout << setprecision(8) << area << endl;
    }

    return 0;
}


