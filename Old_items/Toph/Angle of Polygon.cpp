#include<bits/stdc++.h>
using namespace std;

#define pi 3.1415926536

int main()
{
    int t, n, i;
    double angle;

    cin >> t;

    while(t--)
    {
        cin >> n;

        float tmp = n / 1.0;

        angle = ((n - 2) * 180) / tmp;

        cout << setprecision(6) << angle << endl;
    }

    return 0;
}
