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

#define PI              acos(-1.0)
#define inf             (1 << 61)
#define N               (const int) 1e6+5


using namespace std;
const ll mod = 1e9 + 7;

ll bigmod(ll a, ll b, ll mod)
{
  if (!b)
  {
    ll p = 1 % mod;
    // cout << "returned " << p << '\n';
    return p;
  }

  ll x = bigmod(a, b / 2, mod);
  // cout << "x after big " << x << '\n';
  x = ((x % mod) * (x % mod)) % mod;
  // cout << "x after mod " << x << '\n';

  if (b & 1) x = ((x % mod) * (a % mod)) % mod;
  // cout << "x after odd " << x << '\n';
  // cout << a << ' ' << b << ' ' << x << '\n';

  return x;
}

ll inv(ll a, ll b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}


int main()
{
  fastio;
  //cout << (549755289600) % mod << '\n';

  int tt = 1;

  //cin >> tt;

  while (tt--)
  {
    ll n;
    cin >> n;

    ll tot = bigmod(4LL, n, mod), dif = bigmod(2LL, n, mod);
    ll up = (tot + dif) % mod;
    ll x = inv(2, mod);
    //cout << tot << ' ' << dif << ' ' << up << '\n';

    cout << (up * x) % mod << '\n';
  }

  return 0;
}