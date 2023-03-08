#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int cx, cy, px, py, r, test, xpr, xnr, ypr, ynr, distance;

    cin >> test;

    for(int i = 1; i <= test; i++)
    {
        cin >> cx >> cy >> r >> px >> py;

        xpr = cx + r;
        xnr = cx - r;
        ypr = cy + r;
        ynr = cy - r;

        distance = sqrt(((cx - px) * (cx - px)) + ((cy - py) * (cy - py)));

        printf("Case %d: ", i);

        //if((px < xpr && px > xnr) && (py < ypr && py > ynr))
        if(distance < r)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
