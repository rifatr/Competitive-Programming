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

#define lop(n)          for(int i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)
#define loop(k, a, b)   for(int k = a; k < b; k++)
#define loopr(j, b, a)  for(int j = b; j >= a; j--)
#define lopc(i, a, b, c) for(int i = a; i < b; i += c)

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

#define mod             (const int) 1e9+7
#define PI              acos(-1.0)
#define inf             (1 << 28)
// #define N               (const int) 1e6+5


using namespace std;

const int N = 400;
int dp[N][N][N], n, k, a[N], cnt;

int f(int pos, int sma, int smb)
{
  cnt++;
  if (pos >= n)
  {
    if (sma >= k and smb >= k)
    {
      return 0;
    }
    return inf;
  }

  if (dp[sma][smb][pos] != -1)
    return dp[sma][smb][pos];

  int x, y, z;
  x = y = z = inf;

  if (sma < k and smb < k)
    x = f(pos + 1, sma, smb);
  if (sma < k)
    y = 1 + f(pos + 1, sma + a[pos], smb);
  if (smb < k)
    z = 1 + f(pos + 1, sma, smb + a[pos]);

  // if (sma >= k and smb >= k)
  //   x = 0;

  // cout << pos << ' ' << sma << ' ' << smb << '\t';

  // cout << x << ' ' << y << ' ' << z << '\n';


  return dp[sma][smb][pos] = min({x, y, z});
}

int main()
{
  fastio;

  int tt;

  cin >> tt;

  while (tt--)
  {
    cnt = 0;
    memset(dp, -1, sizeof dp);

    cin >> n >> k;

    lop(n) cin >> a[i];
    sort(a, a + n);

    int ans = f(0, 0, 0);
    if (ans > n) ans = -1;

    cout << ans << '\n';
  }

  return 0;
}