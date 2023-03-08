#include<bits/stdc++.h>

#define ll long long
#define sc(n) scanf("%d", &n)
using namespace std;

const ll N = 2e7 + 3, mod = 1e9 + 7;
ll ans[N];

int main()
{
  ans[0] = 1;
  for (ll i = 1; i < N; i++)
    ans[i] = (ans[i - 1] * i) % mod;

  int tt, n;
  sc(tt);

  while (tt--)
  {
    sc(n);
    printf("%lld\n", (ans[n * 2] * ans[n - 1]) % mod);
  }
  return 0;
}