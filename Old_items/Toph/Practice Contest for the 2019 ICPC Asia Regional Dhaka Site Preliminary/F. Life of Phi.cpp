#include<bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    return gcd(y, x % y);
}

int main()
{
    int t, n, x, i, j, sum;

    cin >> t;

    while(t--)
    {
        cin >> n;

        sum = 0;
        for(i = 2; i < n; i++) {
            if(gcd(i, n) > 1)
                sum += i;
        }

        cout << sum << endl;
    }

    return 0;
}
