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
// #define inf             (1 << 61)
// #define N               (const int) 1e6+5


using namespace std;

struct Node
{
  ll w, v;

  bool operator < (const Node &b) const
  {
    return w > b.w;
  }
};

const ll N = 2e3 + 7, inf = 1e15;
ll n, m, ans[N], dis[N];
vpll nd[N];

ll bfs(int s)
{
  priority_queue <Node> q;
  Node de; de.v = s, de.w = 0;
  q.push(de);
  lop(n) dis[i] = inf;
  dis[s] = 0;

  while (!q.empty())
  {
    auto uu = q.top();
    ll u = uu.v;
    q.pop();

    for (auto &z : nd[u])
    {
      ll d = dis[u] + z.ss;
      if (d < dis[z.ff] or !dis[z.ff])
      {
        dis[z.ff] = d;
        de.v = z.ff;
        de.w = d;
        q.push(de);
      }
    }
  }

  return !dis[s] ? -1 : dis[s];
}

int main()
{
  fastio;

  cin >> n >> m;
  lop(m)
  {
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;

    if (u == v) ans[u] = ans[u] ? min(ans[u], c) : c;
    else
    {
      nd[u].pb({v, c});
    }
  }

  lop(n)
  {
    if (!ans[i])
      ans[i] = bfs(i);
    else
    {
      ll x = bfs(i);
      ans[i] = x != -1 ? min(x, ans[i]) : ans[i];
    }
  }

  lop(n)
  cout << ans[i] << '\n';

  return 0;
}
