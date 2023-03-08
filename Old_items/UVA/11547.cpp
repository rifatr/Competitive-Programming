#include<bits/stdc++.h>

#define pb push_back
#define ll long long
#define N 205

using namespace std;

int main()
{
    ll t, n;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &n);

        //n = n * 567 / 9 + 7492 * 235 / 47 - 498;

        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;

        n /= 10;
        int x = abs(n % 10);

        cout << x << '\n';
    }
}
