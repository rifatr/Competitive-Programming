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

const int N = 106;
int n, k, w, a[N], dp[N][N];

int f(int p, int c)
{
    if (p >= n or !c)
        return 0;

    if (dp[p][c] != -1)
        return dp[p][c];

    int x = 0, i;
    for (i = p; i < n and a[i] <= a[p] + w; i++, x++);

    // cout << p << ' ' << c << ' ' << x << endl;

    return dp[p][c] = max(x + f(i, c - 1), f(p + 1, c));
}

int main()
{
    fastio;

    int tt, x, ts = 1;

    cin >> tt;

    while (tt--)
    {
        cin >> n >> w >> k;
        lop(n) cin >> x >> a[i];

        sort(a, a + n);
        memset(dp, -1, sizeof dp);

        Case(ts++);
        cout << f(0, k) << '\n';
    }

    return 0;
}