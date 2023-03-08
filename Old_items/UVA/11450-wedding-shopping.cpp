#include<bits/stdc++.h>

#define ll              long long
#define pb              push_back
#define ff              first
#define ss              second

#define yes             cout << "Yes\n"
#define no              cout << "No\n"
#define Case(i)         cout << "Case " << int(i) << ": "
#define dbg(x)          cout << #x << "=" << x << endl
#define dbg2(x, y)      cout << #x << " = " << x << "\t" << #y << " = " << y << endl

#define lop(n)          for(int i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)

#define all(x)          x.begin(), x.end()
#define sorta(x)        sort(x.begin(), x.end())
#define sortd(x)        sort(x.rbegin(), x.rend())
#define mem0(a)         memset(a, 0, sizeof(a))
#define mem1(a)         memset(a, -1, sizeof(a))

#define vin             vector <int>
#define vll             vector <ll>
#define vst             vector <string>
#define pll             pair <ll, ll>
#define pii             pair <int, int>
#define pss             pair <string, string>
#define vpll            vector <pll>
#define vpii            vector <pii>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define PI              acos(-1.0)

using namespace std;

const int N = 206, inf = 1 << 30;
int n, c, dp[N][21];
vector <int> garments[21];

int f(int m, int p)
{
  if (m < 0)
    return -inf;

  if (p >= c)
    return 0;

  int &x = dp[m][p];
  if (x != -1)
    return x;

  x = -inf;
  for (auto &z : garments[p])
    x = max(x, z + f(m - z, p + 1));

  return x;
}

int main()
{
  fastio;

  int tt, n;

  cin >> tt;

  while (tt--)
  {
    cin >> n >> c;

    for (int i = 0; i < c; i++)
    {
      int x; cin >> x;
      while (x--)
      {
        int y;
        cin >> y;
        garments[i].pb(y);
      }
    }

    memset(dp, -1, sizeof dp);
    int ans = f(n, 0);

    if (ans > 0) cout << ans << '\n';
    else cout << "no solution\n";

    for (int i = 0; i < c; i++)
      garments[i].clear();
  }

  return 0;
}