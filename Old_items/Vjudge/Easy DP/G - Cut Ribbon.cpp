#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define inf -99999999

const int N = 4004;
int dp[N], ribbon[3];

int fnd(int n)
{
    if(n == 0)
        return 0;

    if(n < ribbon[0])
        return inf;

    if(dp[n] != -1)
        return dp[n];

    int piece[3];

    lop(0, 3)
        piece[i] = 1 + fnd(n - ribbon[i]);

    return dp[n] = max({piece[0], piece[1], piece[2]});
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    memset(dp, -1, sizeof dp);

    cin >> n >> ribbon[0] >> ribbon[1] >> ribbon[2];

    sort(ribbon, ribbon + 3);

    cout << fnd(n) << '\n';

    return 0;
}

