#include<bits/stdc++.h>
#define ll long long

using namespace std;

void OJ()
{
    freopen("1006 in.txt", "r", stdin);
    freopen("1006 out.txt", "w", stdout);
}

ll a, b, c, d, e, f;
ll fn( ll n, ll dp[] ) {
    if( n == 0 ) return a % 10000007;
    if( n == 1 ) return b % 10000007;
    if( n == 2 ) return c % 10000007;
    if( n == 3 ) return d % 10000007;
    if( n == 4 ) return e % 10000007;
    if( n == 5 ) return f % 10000007;
    if(dp[n] == 0)
        dp[n] = ((fn(n-1, dp) % 10000007) + (fn(n-2, dp) % 10000007) + (fn(n-3, dp) % 10000007) + (fn(n-4, dp) % 10000007) + (fn(n-5, dp) % 10000007) + (fn(n-6, dp) % 10000007)) % 10000007;

    return dp[n];
}
int main() {

    //OJ();


    ll n, caseno = 0, cases;
    scanf("%lld", &cases);

//    ll* dp = (ll*) calloc(5, sizeof(ll));
//    cout << dp[0] << endl << dp[1] << endl << dp[4];

    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        ll* dp = (ll*) calloc(n + 1, sizeof(ll));

        printf("Case %lld: %lld\n", ++caseno, fn(n, dp));

        free(dp);
    }
    return 0;
}
