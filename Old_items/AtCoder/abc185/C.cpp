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

#define lop(n)          for(ll i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)
#define loop(k, a, b)   for(ll k = a; k < b; k++)
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

ll fact11;

int main()
{

    fact11 = 1;
    loop(i, 2, 12) fact11 *= i;

    ll test, t = 1, n, k;

    test = 1;

    while (test--)
    {
        cin >> n;
        k = 11;
        n--;

        vector <ll> up, dwn;

        loop(i, n - k + 1, n + 1) up.push_back(i);
        lop(k)
        {
            ll x = i + 1;

            for (ll j = 2; j * j <= x; j++)
            {
                while (x % j == 0)
                {
                    x /= j;
                    dwn.push_back(j);
                }
            }

            if (x > 1) dwn.push_back(x);
        }

        int saiz1 = up.size(), saiz2 = dwn.size();
        lop(saiz2) loop(j, 0, saiz1)
        {
            if (up[j] % dwn[i] == 0)
            {
                up[j] /= dwn[i];
                break;
            }
        }

        ll ans = 1LL;
        lop(saiz1) ans *= up[i];

        printf("%lld\n", ans);
    }

    return 0;
}
