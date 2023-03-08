#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define inf -99999999

const int N = 100010;
ll dp[N], a, freq[N], n;

ll fnd(ll k)
{
    if(k < 0)
        return 0;
    if(dp[k] != -1)
        return dp[k];

    //cout << "k = " << k << '\n';

    dp[k] = max(fnd(k - 1), fnd(k - 2) + (k * freq[k]));
    //cout << k << ' ' << dp[k] << '\n';
    return dp[k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> n;

    lop(0, n) cin >> a, freq[a]++;

    dp[0] = 0, dp[1] = freq[1];

    cout << fnd(N - 1) << '\n';

    return 0;
}


