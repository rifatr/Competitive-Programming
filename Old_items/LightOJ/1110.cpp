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

const int N = 1e2 + 7;
int n, m;
string s, t, lcs[N][N];

string fun(int i, int j)
{
  if (i == n or j == m)
  {
    string zz = "";
    return zz;
  }

  string &x = lcs[i][j];
  if (x.size() != 0)
    return x;

  if (s[i] == t[j])
    x = s[i] + fun(i + 1, j + 1);
  else
  {
    string p = fun(i + 1, j), q = fun(i, j + 1);
    if (p.size() > q.size())
      x = p;
    else if (p.size() < q.size())
      x = q;
    else x = min(p, q);
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
    cin >> s >> t;
    n = s.size(); m = t.size();

    lop(n + 1) lopj(m + 1) lcs[i][j].clear();

    string an = fun(0, 0);

    Case(ts++);
    if (an.size() == 0)
    {
      cout << ":(" << '\n';
      continue;
    }

    cout << an << '\n';
  }

  return 0;
}