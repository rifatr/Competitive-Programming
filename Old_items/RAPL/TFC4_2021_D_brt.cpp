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
// #define N               (const int) 1e4


using namespace std;

double N = 10000;

struct Point
{
  double x, y;
};

double sq(double a)
{
  return a * a;
}

double dff(double  x1, double y1, double  x2, double y2)
{
  return sqrt(sq(x1 - x2) + sq(y1 - y2));
}

int main()
{
  int n;

  while (1)
  {
    scan(n);
    if (!n) break;

    Point a[n];

    lop(n)
    {
      scand2(a[i].x, a[i].y);
    }

    double ans = 1e6;

    lop(n - 1)
    {
      loop(j, i + 1, n)
      {
        double df = dff(a[i].x, a[i].y, a[j].x, a[j].y);
        // printf("%lld %lld %lld %lld %lf\n", a[i].x, a[i].y, a[j].x, a[j].y, df);
        ans = min(ans, df);
      }
    }

    if (ans >= N) printf("INFINITY\n");
    else printf("%.4lf\n", ans);
  }

  return 0;
}