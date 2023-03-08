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

#define mod             (const int) 1e9+7
#define PI              acos(-1.0)
#define inf             (1 << 61)
// #define N               (const int) 1e6+5

using namespace std;

int Set(int n, int pos) {return n = n | (1 << pos);}
int reset(int n, int pos) {return n = n & ~(1 << pos);}
bool check(int n, int pos) {return (bool)(n & (1 << pos));}

const int N = 5e3 + 7;
int n, m, dp[N][N][4];
string s, t;

int f(int i, int j, int op)
{
  if (i == n and j == m)
    return 0;
  if (i == n)
  {
    if (op == 0 or op == 1)
      return  m - j - 1;
    if (op == 2)
      return m - j;
  }
  if (j == m)
  {
    if (op == 0 or op == 1)
      return  n - i - 1;
    if (op == 3)
      return n - i;
  }
  if (dp[i][j][op] != -1)
    return dp[i][j][op];

  int &x = dp[i][j][op];

  if (s[i] == t[j])
    x = f(i + 1, j + 1, 0);
  else
  {
    x = 1 + f(i + 1, j + 1, 1); // replace
    x = min(x, 1 + f(i + 1, j, 2)); // remove from s
    x = min(x, 1 + f(i, j + 1, 3)); // remove from t

    // dp[i][j] = max(f(i + 1, j), f(i, j + 1));
  }

  return x;
}

int main()
{
  fastio;

  cin >> s >> t;
  n = s.size(), m = t.size();

  memset(dp, -1, sizeof dp);

  int p = f(0, 0, 0);

  cout << p << '\n';

  return 0;
}

