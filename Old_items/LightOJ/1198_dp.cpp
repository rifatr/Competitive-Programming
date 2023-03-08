#include<bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 55;
int dp[N][N], my[N], op[N];

int f(int i, int j)
{
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int a, b, c;
    a = b = c = 0;

    for (; j >= 0; j--)
    {
        if (my[i] == op[j])
        {
            a = 1 + f(i - 1, j - 1);
            b = f(i - 1, j);
            c = f(i, j - 1);
            break;
        }
        if (my[i] > op[j])
        {
            c = 2 + f(i - 1, j - 1);
            break;
        }
    }

    return dp[i][j] = max({a, b, c});
}

int main()
{   __
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> my[i];
        for (int i = 0; i < n; i++) cin >> op[i];

        sort(my, my + n);
        sort(op, op + n);

        memset(dp, -1, sizeof dp);
        cout << f(n - 1, n - 1) << '\n';
    }

    return 0;
}