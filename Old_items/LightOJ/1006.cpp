#include<bits/stdc++.h>

using namespace std;

#define mod 10000007
#define ll long long
#define N 10010

ll dp[N];

ll a, b, c, d, e, f;

int fn( int n ) {
    if(dp[n] != -1)
        return dp[n] % mod;

    return dp[n] = ((fn(n-1) % mod) + (fn(n-2) % mod) + (fn(n-3) % mod) + (fn(n-4) % mod) + (fn(n-5) % mod) + (fn(n-6) % mod) ) % mod;
}
int main() {
    int caseno = 0, cases;
    ll n;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        for(int i = 6; i <= n; i++)
            dp[i] = -1;

        dp[0] = a % mod;
        dp[1] = b % mod;
        dp[2] = c % mod;
        dp[3] = d % mod;
        dp[4] = e % mod;
        dp[5] = f % mod;

        if(dp[n] == -1)
            dp[n] = fn(n);

        printf("Case %d: %lld\n", ++caseno, dp[n]);
    }
    return 0;
}
