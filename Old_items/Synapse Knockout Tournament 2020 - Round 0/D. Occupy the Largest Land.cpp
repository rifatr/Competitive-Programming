#include<bits/stdc++.h>

#define pi 2 * acos(0.0)

using namespace std;

int main()
{
    int t;
    double n, l, area, count, x;
    cin >> t;

    while(t--)
    {
        cin >> l >> n;
        x = l / n;

        area = (x * x * n) / (4 * tan(pi / n));

        cout << setprecision(8) << area << endl;
    }

    return 0;
}

