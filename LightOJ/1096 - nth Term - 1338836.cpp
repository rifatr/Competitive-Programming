#include <bits/stdc++.h>
using namespace std;
    #define ll long long
const ll MOD = 10007;
const ll MOD2 = MOD * MOD;   /// Only when (MOD * MOD) fits into long long
#define row 4
#define col 4
ll a, b, c;
struct MatExpo
{
    ll exponents[32][row][col];
    ll ident[row][col] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };  /// Identity Matrix
    ll result[row][col], mat[row][col];
      MatExpo() {
          /// Creating Base Matrix
        ll base[row][col] = { {a, 0, b, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1} };
        memcpy(exponents[0], base, sizeof(base));
          /// Calculating all exponents
        for(ll p = 1; p < 32; p++) {
              for(ll i = 0; i < row; i++) {
                for(ll j = 0; j < col; j++) {
                    ll tmp = 0;
                    for(ll k = 0; k < col; k++) {
                        tmp += exponents[p - 1][i][k] * exponents[p - 1][k][j];
                        while(tmp >= MOD2) /// Taking modulo MOD2 is easy, because we can do it by subtraction
                            tmp -= MOD2;
                    }
                    exponents[p][i][j] = tmp % MOD;
                }
            }
        }
      }
      ll ans(ll m) {
          /// Return from base case
        if(m <= 2)
            return 0;
          memcpy(mat, ident, sizeof(ident));
        ll n = m - 2;   /// Here, (n - 2)th power of base matrix represents the nth term
        for(ll p = 31; p >= 0; p--) {
            if((n >> p) & 1) {
                  for(ll i = 0; i < row; i++) {
                    for(ll j = 0; j < col; j++) {
                        ll tmp = 0;
                        for(ll k = 0; k < col; k++) {
                            tmp += mat[i][k] * exponents[p][k][j];
                            while(tmp >= MOD2) /// Taking modulo MOD2 is easy, because we can do it by subtraction
                                tmp -= MOD2;
                        }
                        result[i][j] = tmp % MOD;
                    }
                }
                  memcpy(mat, result, sizeof(result));
            }
          }
          return (c * result[0][3]) % MOD;
    }
};
// MatExpo ex = MatExpo();
// ans = ex.ans(n);      nth term, term count starts from 0
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
        MatExpo ex = MatExpo();
          printf("Case %lld: %lld\n", ++caseno, ex.ans(n));
    }
      return 0;
}
   
