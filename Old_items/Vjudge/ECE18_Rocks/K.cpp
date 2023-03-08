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

const int N = 3;

bool ismagic(int mat[N][N])
{
  int sum = 0, sum2 = 0;
  for (int i = 0; i < N; i++)
    sum = sum + mat[i][i];

  for (int i = 0; i < N; i++)
    sum2 = sum2 + mat[i][N - 1 - i];

  if (sum != sum2)
    return false;

  for (int i = 0; i < N; i++) {

    int rowSum = 0;
    for (int j = 0; j < N; j++)
      rowSum += mat[i][j];

    if (rowSum != sum)
      return false;
  }

  for (int i = 0; i < N; i++) {

    int colSum = 0;
    for (int j = 0; j < N; j++)
      colSum += mat[j][i];

    if (sum != colSum)
      return false;
  }

  return true;
}

int main()
{
  fastio;

  int a[3][3];

  lop(3) lopj(3) cin >> a[i][j];

  int b[9], ans = 1e6;
  iota(b, b + 9, 1);

  do
  {
    int c[3][3];
    int k = 0;
    lop(3) lopj(3) c[i][j] = b[k++];

    if (ismagic(c))
    {
      int ans2 = 0;
      lop(3) lopj(3) ans2 += abs(a[i][j] - c[i][j]);
      ans = min(ans, ans2);
    }
  }
  while (next_permutation(b, b + 9));

  cout << ans << '\n';

  return 0;
}