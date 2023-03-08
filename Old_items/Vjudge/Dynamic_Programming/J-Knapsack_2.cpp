#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1e2+2, W = 1e5+5;
ll v[N], w[N], dp[N][W], weight;
int n;

ll f(int p, ll wt)
{
    if(p >= n or wt == 0LL)
        return 0;

    if(dp[p][wt] != -1)
        return dp[p][wt];

    ll a = 0, b;
    if(wt - w[p] >= 0)
        a = v[p] + f(p + 1, wt - w[p]);
    b = f(p + 1, wt);

    return dp[p][wt] = max(a, b);
}
int main()
{
    cin >> n >> weight;

    for(int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    memset(dp, -1, sizeof dp);

    cout << f(0, weight) << '\n';

    return 0;
}

