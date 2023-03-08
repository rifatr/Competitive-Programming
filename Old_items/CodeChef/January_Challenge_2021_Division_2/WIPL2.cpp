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
#define inf             (1 << 28)
// #define N               (const int) 1e6+5


using namespace std;

const int N = 4004;
int n, k;

int main()
{
  fastio;

  int tt;

  cin >> tt;

  while (tt--)
  {
    cin >> n >> k;
    vector <int> a(n);

    lop(n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int ans, sma, smb, f;
    f = ans = sma = smb = 0;

    int i = 0;
    for (; i < n; i++)
    {
      if (sma >= k) break;

      if (a[i] + sma <= k)
      {
        sma += a[i];
        ans++;
        a[i] = 0;
      }
      else
        break;
    }
    for (; i < n; i++)
    {
      if (smb >= k) break;

      if (a[i] + smb <= k)
      {
        smb += a[i];
        ans++;
        a[i] = 0;
      }
      else
        break;
    }

    sort(a.rbegin(), a.rend());
    for (int i = n - 1; i >= 0; i--)
    {
      if (!a[i]) a.pop_back();
      else break;
    }
    n = a.size();

    int pre[n + 2]; pre[0] = 0;
    lop(n) pre[i + 1] = pre[i] + a[i];

    int nda = k - sma, ndb = k - smb;
    if (ndb < nda) swap(ndb, nda);
    int cur = inf, nn, mm, curp = inf;

    cout << sma << ' ' << smb << '\n';
    lop(n) cout << a[i] << ' ';

    for (int p = i; p < n; p++)
    {
      for (int q = p; q < n; q++)
      {
        int xx = pre[p + 1] - pre[q];
        if (xx >= ndb and q - p + 1 < curp)
          curp = q - p + 1, nn = p, mm = q, cur = xx;
        if (xx >= ndb and q - p + 1 == curp and xx < cur)
          curp = q - p + 1, nn = p, mm = q, cur = xx;
      }
    }

    ndb -= cur;
    ans += curp;
    for (int p = nn; p <= mm; p++)
      a[p] = 0;

    sort(a.rbegin(), a.rend());
    lop(n)
    {
      if (nda <= 0) break;

      nda -= a[i];
      ans++;
    }



    /*lop(n)
    {
      if (sma >= k) break;

      if (a[i] + sma <= k)
      {
        sma += a[i];
        ans++;
        a[i] = 0;
      }

      else
      {
        int need = k - sma, cur = inf, nn, mm, curp = inf;
        if (!need) continue;
        for (int p = i; p < n; p++)
        {
          for (int q = p; q < n; q++)
          {
            int xx = pre[p + 1] - pre[q];
            if (xx >= need and q - p + 1 < curp)
              curp = q - p + 1, nn = p, mm = q, cur = xx;
            if (xx >= need and q - p + 1 == curp and xx < cur)
              curp = q - p + 1, nn = p, mm = q, cur = xx;
          }
        }

        sma += cur;
        ans += curp;
        for (int p = nn; p <= mm; p++)
          a[p] = 0;
      }
    }

    sort(a.rbegin(), a.rend());
    for (int i = n - 1; i >= 0; i--)
    {
      if (!a[i]) a.pop_back();
      else break;
    }
    n = a.size();
    lop(n) pre[i + 1] = pre[i] + a[i];

    lop(n)
    {
      if (smb >= k) break;

      if (a[i] + smb <= k)
      {
        smb += a[i];
        ans++;
        // cout << smb << ' ';
      }

      else
      {
        int need = k - smb, cur = inf, nn, mm, curp = inf;
        for (int p = i; p < n; p++)
        {
          for (int q = p; q < n; q++)
          {
            int xx = pre[p + 1] - pre[q];
            if (xx >= need and q - p + 1 < curp)
              curp = q - p + 1, nn = p, mm = q, cur = xx;
          }
        }

        smb += cur;
        ans += curp;
      }
    }

    lop(n)
    {
      if (smb >= k) break;

      smb += a[i];
      ans++;
    }

    if (sma < k or smb < k)
      ans = -1;*/

    // cout << sma << ' ' << smb << '\n';

    if (nda > 0 or ndb > 0)
      ans = -1;
    cout << ans << '\n';
  }

  return 0;
}