#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c, d, e, f;
//ll fn( ll n ) {
//    if( n == 0 ) return a;
//    if( n == 1 ) return b;
//    if( n == 2 ) return c;
//    if( n == 3 ) return d;
//    if( n == 4 ) return e;
//    if( n == 5 ) return f;
//    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
//}
int main() {
    ll n, caseno = 0, cases, i;
    vector <ll> arr;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        arr.push_back(a % 10000007);
        arr.push_back(b % 10000007);
        arr.push_back(c % 10000007);
        arr.push_back(d % 10000007);
        arr.push_back(e % 10000007);
        arr.push_back(f % 10000007);

        for(i = 6; i <= n; i++) {
            arr.push_back(((arr[i - 1]) + (arr[i - 2]) + (arr[i - 3]) + (arr[i - 4]) + (arr[i - 5]) + (arr[i - 6])) % 10000007);
            //cout << " v = " << arr[i] << endl;;
        }

        printf("Case %lld: %lld\n", ++caseno, arr[n]);

        arr.clear();
    }
    return 0;
}

