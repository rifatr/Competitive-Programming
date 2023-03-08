#include<bits/stdc++.h>

using namespace std;

const int N = 100005;
int dp[N], ar[N], n, m;
bool vis[N];

int cnt(int k)
{
    if(k == n)
        return 0;

    dp[k] = cnt(k + 1) + 1 - vis[ar[k]];

    vis[ar[k]] = 1;

    return dp[k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> ar[i];

    int p = cnt(0);

    for(int i = 0; i < m; i++)
    {
        cin >> p;
        cout << dp[--p] << '\n';
    }

    return 0;
}
