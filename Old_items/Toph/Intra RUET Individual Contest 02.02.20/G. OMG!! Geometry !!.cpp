#include<bits/stdc++.h>

using namespace std;

int main()
{
    double r; //, a, area;
    int t;

    cin >> t;

    while(t--)
    {
        cin >> r;

//        a = 4 * r * r;
//
//        area = a - (3.14 * r * r);

        cout << setprecision(8) << 0.86 * r * r << endl;
    }

    return 0;
}
