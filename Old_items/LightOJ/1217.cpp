#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int N = 1e3 + 5;
int dp[N], h[N], n, lmt;

int f(int p)
{
    if (p >= lmt)
        return 0;
    if (dp[p] != -1)
        return dp[p];

    int x = h[p] + f(p + 2);
    x = max(x, f(p + 1));

    return dp[p] = x;
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        cin >> n;
        lop(n) cin >> h[i];
        int ans = 0;

        memset(dp, -1, sizeof dp);
        lmt = n - 1, ans = f(0);
        memset(dp, -1, sizeof dp);
        lmt = n, ans = max(ans, f(1));

        cout << ans << '\n';
    }

    return 0;
}