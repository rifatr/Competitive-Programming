#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, test;

    cin >> test;

    for(int i = 1; i <= test; i++)
    {
        cin >> a >> b;

        //printf("Case %d: ", i);
        cout << __gcd(a, b) << endl;
    }

    return 0;
}

