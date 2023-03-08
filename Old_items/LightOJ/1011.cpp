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
#define pll             pair <int, int>
#define pss             pair <string, string>
#define vpll            vector <pll>
#define sv              set <vpll>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

// #define mod             (const ll) 1e9+7
#define PI              acos(-1.0)
#define inf             (1 << 28)
// #define N               (const int) 1e6+5

using namespace std;

const int N = 16;
int n, m, dp[N][(1 << 16) + 2], a[N][N];

int fun(int i, int mask)
{
  if (i == n)
    return mask & ((1 << i) - 1) ? 0 : -inf;

  int &x = dp[i][mask];
  if (x != -1) return x;

  lopj(n)
  {
    if ((1 << j) & mask)
      continue;

    x = max(x, a[i][j] + fun(i + 1, mask | (1 << j)));
  }

  return x;
}

int main()
{
  fastio;

  int tt, ts = 1;

  cin >> tt;

  while (tt--)
  {
    cin >> n;

    lop(n) lopj(n) cin >>  a[i][j];

    memset(dp, -1, sizeof dp);

    Case(ts++);
    cout << fun(0, 0) << '\n';
  }

  return 0;
}