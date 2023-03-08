#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long x, test, y;

    cin >> test;

    while(test--)
    {
        cin >> x >> y;

        cout << "LCM = " << (x * y) / gcd(x, y) << '\n';
    }

    return 0;
}

