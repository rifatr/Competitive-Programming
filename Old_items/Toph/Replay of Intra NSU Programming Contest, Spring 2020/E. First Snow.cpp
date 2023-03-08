
/*
* rifatrraazz
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, x, d, i, j, total = 0, inp;

    cin >> n >> x >> d;

    long long v[n];

    for(i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            v[j] -= d;
        }

        total = 0;
        for(j = 0; j <= i; j++)
        {
            if(v[j] > 0)
                total += v[j];

            if(total >= x)
                break;
        }

        if(total >= x) {
            cout << j + 1 << endl;
            break;
        }
    }

    return 0;
}
