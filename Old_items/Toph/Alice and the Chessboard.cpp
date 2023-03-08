#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, c, d;

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c >> d;

        if(abs(a - c) == abs(b - d))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
