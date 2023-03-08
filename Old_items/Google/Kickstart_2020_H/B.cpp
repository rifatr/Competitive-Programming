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

ll dgt[20], sm[21];

ll pwr(ll n, ll x)
{
  if (x == 0) return 1;

  ll p = 1;
  while (x--) p *= n;
  return p;
}

void fn()
{
  dgt[1] = 1;
  dgt[2] = sm[2] = 5;

  for (int i = 3; i < 20; i++)
  {
    dgt[i] = dgt[i - 1] * 5;
    sm[i] = sm[i - 1] + dgt[i];
  }
}

string ltos(ll p)
{
  string s;
  while (p)
  {
    s.push_back( (char) 48 + (p % 10));
    p /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

ll calc(ll x)
{
  if (x < 1) return 0;

  string b = ltos(x);
  int m = b.size();

  ll ans2 = 0;
  int pst = 0;
  for (; pst < m; pst++)
    if (pst % 2 == b[pst] % 2)
      break;

  bool f = (m & 1);
  int ps = m - pst + 1;
  if (!(ps & 1)) f ^= 1;
  for (int i = pst - 1; i >= 0; i--)
  {
    int z = (10 - (b[i] - '0') + f - (i < m - 1)) / 2;
    ans2 += z * dgt[ps++];
    f ^= 1;
    //cout << i << ' ' << z << ' ' << ans2 << '\n';
  }

  if (pst < m)
  {
    int z = (b[pst] - '0' + 1) / 2;
    ans2 += (dgt[m - pst] * z) + sm[m - pst];
  }

  //ans2 += dgt[m - 1];
  return ans2;
}

int main()
{
  fastio;

  fn();

  int tt, t = 1;

  cin >> tt;

  while (tt--)
  {
    ll l, r;
    cin >> l >> r;

    /*string a = ltos(l), b = ltos(r);
    int n = a.size(), m = b.size();

    ll pw = pwr(10, n - 1);
    for (int i = 0; i < n; i++)
    {
      if (i % 2 == a[i] % 2)
        l += pw;
      pw /= 10;
    }

    cout << l << ' ' << r << '\n';

    a = ltos(l);
    ll ans = 0;
    bool f = (n & 1);
    int ps = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      int z = (10 - (a[i] - '0') + f - (i < n - 1)) / 2;
      ans += z * dgt[ps++];
      f ^= 1;
      //cout << i << ' ' << z << ' ' << ans << '\n';
    }

    for (int i = n + 1; i < m; i++)
      ans += 5 * dgt[i];*/

    ll x = calc(r), y = calc(l - 1);

    cout << x << ' ' << y << '\n';

    cout << x - y << '\n';
  }

  return 0;
}

