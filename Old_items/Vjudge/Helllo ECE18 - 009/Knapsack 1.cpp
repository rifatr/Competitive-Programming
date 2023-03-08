#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)

const int N = 1e2 + 2, NN = 1e5+5;
ll n, w[N], v[N];
ll dp[N][NN], inf = 1 << 16;

ll f(int p, int W)
{
    if(p == n)
        return 0;

    if(dp[p][W] != -1) {
        return dp[p][W];
    }

    ll ans = f(p + 1, W);
    if(W >= w[p])
        ans = max(ans, f(p + 1, W - w[p]) + v[p]);

    return dp[p][W] = ans;
}

int main()
{
    int W;

    cin >> n >> W;

    lop(n) cin >> w[i] >> v[i];

    memset(dp, -1, sizeof dp);

    cout << f(0, W) << endl;

    return 0;
}
