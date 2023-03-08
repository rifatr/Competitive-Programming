#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int x[N], h[N], n, dp[N];

int f(int k)
{
    if(k == n)
        return 0;

    if(k == n - 1)
        return dp[k] = 1;

    if(x[k] - h[k] > x[k - 1])
        return dp[k] = 1 + f(k + 1);

    if(x[k] + h[k] < x[k + 1])
    {
        x[k] += h[k];
        return dp[k] = 1 + f(k + 1);
    }

    return dp[k] = f(k + 1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> h[i];

    dp[0] = 1;

    cout << dp[0] + f(1) << '\n';

    return 0;
}
