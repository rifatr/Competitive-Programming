#include<bits/stdc++.h>
using namespace std;

#define pi 3.1415926536

int main()
{
    int t, a, i, j;
    float area, perim;

    cin >> t;

    while(t--)
    {
        cin >> a;

        float r = sqrt(a) / 2;

        area = a - (pi * r * r);
        perim = 2 * pi * r;

        cout << setprecision(10) << area << " " << perim << endl;
    }

    return 0;
}
