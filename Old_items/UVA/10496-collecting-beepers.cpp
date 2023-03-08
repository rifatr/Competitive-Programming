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

int Set(int n, int pos) {return n = n | (1 << pos);}
int reset(int n, int pos) {return n = n & ~(1 << pos);}
bool check(int n, int pos) {return (bool)(n & (1 << pos));}

const int N = 11, inf = 1 << 25;
int n, dp[N][1 << N], x, y, sx, sy;
pii beps[N];

int dis(int x1, int y1, int x2, int y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}

int f(int pos, int mask)
{
  if (__builtin_popcount(mask) == n)
    return dis(sx, sy, beps[pos].ff, beps[pos].ss);

  int &ret = dp[pos][mask];
  if (ret != -1)
    return ret;

  ret = inf;
  for (int i = 0; i < n; i++)
  {
    if (!mask)
      ret = min(ret, dis(sx, sy, beps[i].ff, beps[i].ss) + f(i, mask | (1 << i)));
    else if (!(mask & (1 << i)))
      ret = min(ret, dis(beps[pos].ff, beps[pos].ss, beps[i].ff, beps[i].ss) + f(i, mask | (1 << i)));
  }

  return ret;
}

int main()
{
  fastio;

  int tt;

  cin >> tt;

  while (tt--)
  {
    cin >> x >> y >> sx >> sy >> n;

    lop(n) cin >> beps[i].ff >> beps[i].ss;

    memset(dp, -1, sizeof dp);
    cout << "The shortest path has length " << f(0, 0) << '\n';
  }

  return 0;
}