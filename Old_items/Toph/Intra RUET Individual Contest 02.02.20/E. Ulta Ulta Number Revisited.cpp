#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long t, k, i, j, a, b;
    string x, y, z;

    //printf("%d", '9');

    cin >> t;

    while(t--)
    {
        cin >> k;

        k *= 10;

        for(i = k - 9; i < k; i++)
        {
            x = to_string(i);
            int l = x.size();
            //cout << x;
            for(j = 0, a = l - 1; j < l; j++, a--)
            {
                y[j] = '9' - x[j] + 1;
                z[a] = y[j];
            }
            cout << y << endl << z << endl << endl;
            x.clear(); y.clear(); z.clear();
        }
    }
}
