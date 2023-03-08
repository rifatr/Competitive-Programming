#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long a, b, avg, l, s, k, m;

    while(1)
    {
        cin >> a >> b;

        if(a == b)
            return 0;

        avg = (a + b) / 2;

        if(a > b) {
            l = a;
            s = b;
        }
        else {
            l = b;
            s = a;
        }

        //cout << avg << " " << l << " " << s << endl;

        if(l - avg == avg - s)
            cout << avg - s << endl;
        else
            cout << "impossible\n";
    }
}
