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

#define yes             cout << "Yes\n"
#define no              cout << "No\n"
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

#define mod             (const int) 1e9+7
#define PI              acos(-1.0)
#define inf             (1 << 61)
#define N               (const int) 1e6+5


using namespace std;


int main()
{
  fastio;

  int h, w;
  cin >> h >> w;

  char grid[h][w];
  lop(h) lopj(w) cin >> grid[i][j];

  int ans = 0, a = 0, b = 0;

  lop(h)
  {
    lopj(w)
    if (grid[i][j] == '#')
    {
      a = i;
      b = j;
      break;
    }

    if (a and b)
      break;
  }

  for (; b < w; b++)
    if (grid[a][b] != '#')
    {
      b--;
      break;
    }

  ans = 3;

  cout << a << ' ' << b << endl;

  for (int i = a, j = b; i < h - 1; i++, j++)
  {
    if (a == b)
    {
      ans++;
      break;
    }
    if (grid[i + 1][a] == '.')
    {
      if (grid[i][a - 1] == '#')
      {
        for (; a; a--)
          if (grid[i][a] == '.')
            break;
      }
      else
      {
        for (; a; a++)
          if (grid[i][a] == '.')
            break;
      }
      ans += 2;
    }

    if (a == b)
    {
      ans++;
      break;
    }

    if (grid[i + 1][b] == '.')
    {
      if (grid[i][b - 1] == '#')
      {
        for (; b; b++)
          if (grid[i][b] == '.')
            break;
      }
      else
      {
        for (; b; b--)
          if (grid[i][b] == '.')
            break;
      }
      ans += 2;
    }

    cout << a << ' ' << b << ' ' << ans << endl;

  }

  cout << ans << endl;

  return 0;
}
