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

const ll N = 2e2 + 7, M = 55, mod = 1e8 + 7;
ll n, grid[N][N], dp[N][N], k;

ll f(ll i, ll j)
{
  if (!grid[i][j])
    return 0;

  ll &x = dp[i][j];

  if (x != -1) return x;

  x = grid[i][j];
  if (i < n)
  {
    x += max(f(i + 1, j), f(i + 1, j + 1));
  }
  else
  {
    x += max(f(i + 1, j), f(i + 1, j - 1));
  }

  return x;
}

int main()
{
  fastio;

  int tt, t = 1;

  cin >> tt;

  while (tt--)
  {
    cin >> n;
    memset(grid, 0, sizeof grid);

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++)
        cin >> grid[i][j];
    for (int i = 1; i < 2 * n; i++)
      for (int j = 1; j <= n - i; j++)
        cin >> grid[i + n][j];

    memset(dp, -1, sizeof dp);

    Case(t++);
    cout << f(1, 1) << '\n';
  }

  return 0;
}