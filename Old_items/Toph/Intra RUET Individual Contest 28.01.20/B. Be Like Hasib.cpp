#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x, i = 0, l, h, m;

    cin >> n >> x;

    l = 0;
    h = n;


    while(1)
    {
        m = (l + h) / 2;
        if((l + h) % 2 != 0)
            m++;

        if(x > m)
            l = m;
        else
            h = m;

        i++;

        if(l + 1 >= h)
            break;
    }

    cout << i << endl;

    return 0;
}
