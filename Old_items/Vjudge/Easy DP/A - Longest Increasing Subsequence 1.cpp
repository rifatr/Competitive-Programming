#include<bits/stdc++.h>

using namespace std;

const int N = 11;
int n;
int ara[N], lis[N];

int lis_dp(int x)
{
    if(x < 0)
        return 0;

    if(lis[x])
        return lis[x];

    int is = 0;

    for(int i = 0; i < x; i++)
        if(ara[i] < ara[x])
            is = max(is, lis_dp(i));

    return lis[x] = is + 1;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> ara[i], lis[i] = 0;

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans = max(ans, lis_dp(i));

    cout << ans << '\n';

    return 0;
}
