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
#define inf             (1 << 61)
#define N               (const int) 1e6+5


using namespace std;


int main()
{
  fastio;

  ll n, m;
  cin >> n >> m;

  if(m == 0) {
    cout << 1 << '\n';
    return 0;
  }

  ll a[m];
  lop(m) cin >> a[i];

  if(m == n) {
    cout << 0 << '\n';
    return 0;
  }

  sort(a, a + m);

  ll ans = a[0] > 1 ? a[0] - 1 : 1e18;
//  cout << ans << ' ';

  loop(i, 1, m)
  {
      if(a[i] - a[i - 1] < 2) continue;
//      cout << a[i] << ' ' << a[i - 1] << '\n';
      ans = min(ans, a[i] - a[i - 1] - 1);
//      cout << ans << ' ';
  }

  if(a[m - 1] < n)
  ans = min(ans, n - a[m - 1]);
  ll k = ans - 1;
//  cout << ans << '\n';

  ll res = 0;
  if(a[0] > 1) res += (a[0] - 1 + k) / ans;
//  cout << res << '\n';
  loop(i, 1, m)
  {
      if(a[i] - a[i - 1] < 2) continue;
      res += (a[i] - a[i - 1] - 1 + k) / ans;
//      cout << res << '\n';
  }

  res += (n - a[m - 1] + k) / ans;

    cout << res << '\n';

  return 0;
}


