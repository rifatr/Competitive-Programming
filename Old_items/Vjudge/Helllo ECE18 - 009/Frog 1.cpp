#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 1; i <= b; i++)

const int N = 1e5+4, K = 1e2+2;
const ll inf = 1e16;
int h[N], n, k;
ll dp[K][N];

ll f(int j, int t)
{
    if(j > n)
        return inf;

    if(dp[t][j] != -1)
        return dp[t][j];

    ll ans = inf;

    lop(k) ans = min(ans, f(j + i, i));

    if(ans == inf)
        ans = 0;

    return dp[t][j] = abs(h[j] - h[j - t]) + ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    lop(n)
        cin >> h[i];

    memset(dp, -1, sizeof dp);

    cout << f(1, 0) << '\n';

    return 0;
}
