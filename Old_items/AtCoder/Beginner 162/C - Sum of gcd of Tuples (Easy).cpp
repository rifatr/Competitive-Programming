#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    long  long n, i, j, k, sum = 0, x;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            for(k = 1; k <= n; k++)
            {
                x = gcd(i, j);
                sum += gcd(x, k);
            }
        }
    }

    cout << sum << endl;

    return 0;
}
