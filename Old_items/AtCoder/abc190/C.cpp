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

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             (const int) 1e9+7
#define PI              acos(-1.0)
#define inf             (1 << 61)
#define N               (const int) 105


using namespace std;

int n, m, k;
pll con[N], bal[20];
int dp[N];

int dfs(int p, vin al)
{
  if (p == k)
  {
    // lop(al.size()) cout << al[i] << ' ';
    // cout << '\n';
    int c = 0;
    lop(m)
    {
      int sz = al.size();
      pair <bool, bool> cc = {0, 0};
      lopj(sz)
      {
        if (al[j] == con[i].ff)
          cc.ff = 1;
        if (al[j] == con[i].ss)
          cc.ss = 1;
      }
      if (cc.ff and cc.ss)
        c++;
    }
    return c;
  }

  // if (dp[p] != -1)
  //   return dp[p];

  al.pb(bal[p].ff);
  dp[p] = max(dp[p], dfs(p + 1, al));
  al.pop_back();
  al.pb(bal[p].ss);
  dp[p] = max(dp[p], dfs(p + 1, al));

  return dp[p];
}

int main()
{
  fastio;

  cin >> n >> m;

  lop(m) cin >> con[i].ff >> con[i].ss;

  cin >> k;
  lop(k) cin >> bal[i].ff >> bal[i].ss;

  memset(dp, -1, sizeof dp);


  vin al;
  int ans = dfs(0, al);

  cout << ans << '\n';

  return 0;
}
