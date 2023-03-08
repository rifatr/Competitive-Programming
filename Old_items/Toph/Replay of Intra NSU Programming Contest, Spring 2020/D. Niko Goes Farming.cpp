/*
* rifatrraazz
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, p, i, h, w, a;

    cin >> t;

    while(t--)
    {
        cin >> p;

        p /= 2;

        h = p / 2;
        w = p - h;

        cout << h * w << endl;
    }

    return 0;
}

