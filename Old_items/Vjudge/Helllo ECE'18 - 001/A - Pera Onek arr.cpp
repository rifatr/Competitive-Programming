#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c, d, e, f;

int main() {
    ll n, caseno = 0, cases, i;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        ll arr[n + 1];

        arr[0] = a % 10000007;
        arr[1] = b % 10000007;
        arr[2] = c % 10000007;
        arr[3] = d % 10000007;
        arr[4] = e % 10000007;
        arr[5] = f % 10000007;

        for(i = 6; i <= n; i++) {
            arr[i] = ((arr[i - 1] % 10000007) + (arr[i - 2] % 10000007) + (arr[i - 3] % 10000007) + (arr[i - 4] % 10000007) + (arr[i - 5] % 10000007) + (arr[i - 6] % 10000007)) % 10000007;
            //cout << " v = " << arr[i] << endl;
        }

        printf("Case %lld: %lld\n", ++caseno, arr[n]);
    }
    return 0;
}


