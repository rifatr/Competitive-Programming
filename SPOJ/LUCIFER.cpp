#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll dp[2][2][12][85][85];
vector <ll> num;
bool check[105];

ll solve(ll isStart, ll isSmall, ll pos, ll odd, ll even)

{
    if(pos == 0) {
        if(even - odd < 0)
            return 0;
        else if(check[even - odd] == 0)
            return 1;
        else
            return 0;
    }
    ll &ret = dp[isStart][isSmall][pos][odd][even];
    if(ret != -1 && isSmall)
        return ret;

    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];

    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (pos & 1) ? odd + i: odd, !(pos & 1) ? even + i: even);
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (pos & 1) ? odd + i: odd, !(pos & 1) ? even + i: even);

        if(pos > 1)
            rt += solve(1, 1, pos - 1, 0, 0);
    }

    return ret = rt;
}

ll calc(ll n)

{
    if(n < 10)
        return 0;

    ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % 10);
        tmp /= 10;
    }
    reverse(num.begin(), num.end());

    return solve(1, 0, num.size(), 0, 0);
}

bool isPrime(ll n)

{
    ll sqt = sqrt(n);
    for(ll i = 2; i <= sqt; i++)
        if(n % i == 0)
            return 0;

    return 1;
}

int main()

{
    check[0] = 1;
    check[1] = 1;
    for(ll i = 2; i <= 100; i++)
        if(!isPrime(i))
            check[i] = 1;

    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);

        ll ans = calc(r);

        ans -= calc(l - 1);

        printf("%lld\n", ans);
    }

    return 0;
}
