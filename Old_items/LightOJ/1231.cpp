#include<bits/stdc++.h>

#define ll              long long
#define pb              push_back
#define ff              first
#define ss              second
#define mp              make_pair

#define scan(a)         scanf("%d", &a)
#define scanl(a)        scanf("%lld", &a)
#define scand(a)        scanf("%lf", &a)
#define scan2(a, b)     scanf("%d %d", &a, &b)
#define scanl2(a, b)    scanf("%lld %lld", &a, &b)
#define scand2(a, b)    scanf("%lf %lf", &a, &b)

#define yes             cout << "yes\n"
#define no              cout << "no\n"
#define Case(i)         cout << "Case " << int(i) << ": "
#define dbg(x)          cout << #x << "=" << x << endl
#define dbg2(x, y)      cout << #x << " = " << x << "\t" << #y << " = " << y << endl

#define lop(n)          for(int i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)
#define loop(k, a, b)   for(int k = a; k < b; k++)
#define loopr(j, b, a)  for(int j = b; j >= a; j--)

#define all(x)          x.begin(), x.end()
#define sorta(x)        sort(x.begin(), x.end())
#define sortd(x)        sort(x.rbegin(), x.rend())
#define mem0(a)         memset(a, 0, sizeof(a))
#define mem1(a)         memset(a, -1, sizeof(a))

#define vin             vector <int>
#define vll             vector <ll>
#define vst             vector <string>
#define pll             pair <ll, ll>
#define pss             pair <string, string>
#define vpll            vector <pll>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

// #define mod             (const ll) 1e9+7
#define PI              acos(-1.0)
#define inf             (1LL << 61)
// #define N               (const int) 1e6+5

using namespace std;

const ll N = 1e3 + 7, M = 55, mod = 1e8 + 7;
ll n, coin[M], cnt[M], dp[M][N], k;

ll f(ll p, ll w)
{
  if (p >= n or w <= 0)
  {
    if (!w) return 1;
    return 0;
  }

  ll &x = dp[p][w];

  if (x != -1) return x;

  x = 0;
  for (ll i = 0; i <= cnt[p]; i++)
    if (w - (i * coin[p]) >= 0LL)
      x = (x + f(p + 1, w - (i * coin[p]))) % mod;

  return x;
}

int main()
{
  fastio;

  int tt, t = 1;

  cin >> tt;

  while (tt--)
  {
    cin >> n >> k;
    lop(n) cin >> coin[i];
    lop(n) cin >> cnt[i];

    memset(dp, -1, sizeof dp);

    Case(t++);
    cout << f(0, k) << '\n';
  }

  return 0;
}