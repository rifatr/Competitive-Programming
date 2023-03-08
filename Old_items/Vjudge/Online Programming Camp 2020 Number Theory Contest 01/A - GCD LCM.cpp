#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, g, l, a, b;

    cin >> t;

    while(t--)
    {
        cin >> g >> l;

        a = -1;
        long long x = g * l;
        for(b = g; b <= l; b++)
        {
            if(x % b == 0)
            {
                a = x / b;
                if((a % g != 0 or b % g != 0) or (l % a != 0 or l % b != 0)) {
                    a = -1;
                    break;
                }
                else
                    break;

                //cout << a << " " << b << endl;
            }
            else break;
        }

        if(a == -1)
            cout << a << '\n';
        else
            cout << min(a, b) << " " << max(a, b) << '\n';
    }
}
