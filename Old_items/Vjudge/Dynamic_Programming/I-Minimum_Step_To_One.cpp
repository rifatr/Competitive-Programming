#include<bits/stdc++.h>

using namespace std;

const int N = 2e7 + 7, inf = (1 << 30);
int dp[N];

int f(int n)
{
    if(n == 1)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int a, a1, a2;
    a = a1 = a2 = inf;

    a = 1 + f(n - 1);
    if(n % 2 == 0) a1 = 1 + f(n / 2);
    if(n % 3 == 0) a2 = 1 + f(n / 3);

    return dp[n] = min({a, a1, a2});
}

int main()
{
    int tt, t = 1;
    cin >> tt;

    memset(dp, -1, sizeof dp);

    while(tt--)
    {
        int n;
        cin >> n;

        cout << "Case " << t++ << ": ";
        cout << f(n) << '\n';
    }

    return 0;
}
