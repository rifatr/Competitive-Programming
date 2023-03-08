#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 1; i <= b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

const int N = 1e5+4;
int w[4][N], n;
ll dp[4][N];

ll f(int j, int t)
{
    if(j > n)
        return 0;

    if(dp[t][j] != -1)
        return dp[t][j];

    ll ans[4] = {0};

    loop(i, 1, 4)
    {
        if(i == t) continue;

        ans[i] = f(j + 1, i) + w[i][j];
    }

//    cout << j << ' ' << t << ' ';
//    loop(i, 1, 4) cout << ans[i] << ' ';

    dp[t][j] = *max_element(ans, ans + 4);

//    cout << dp[t][j] << endl;

    return dp[t][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    lop(n)
        cin >> w[1][i] >> w[2][i] >> w[3][i];

    memset(dp, -1, sizeof dp);

    cout << f(0, 0) << '\n';

    return 0;
}

