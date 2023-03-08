#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 1; i <= b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

const int N = 22, inf = 1 << N;
int w[4][N], n;
ll dp[4][N];

ll f(int j, int t)
{
    if (j > n)
        return 0;

    if (dp[t][j] != -1)
        return dp[t][j];

    ll ans = inf;

    loop(i, 1, 4)
    {
        if (i == t) continue;

        ans = min(ans, f(j + 1, i));
    }

    return dp[t][j] = ans + w[t][j];
}

int main()
{
    int test;

    cin >> test;

    for (int t = 1; t <= test; t++)
    {
        cin >> n;

        lop(n)
        cin >> w[1][i] >> w[2][i] >> w[3][i];

        memset(dp, -1, sizeof dp);

        ll x = f(1, 1), y = f(1, 2), z = f(1, 3);

        cout << "Case " << t << ": " << min({x, y, z}) << '\n';
    }

    return 0;
}