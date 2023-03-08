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
#define Case(i)         cout << "Case #" << int(i) << ": "

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

string s, a = "KICK", b = "START";


int main()
{
    fastio;

    int tt, n, t = 1;

    cin >> tt;

    while(tt--)
    {
        cin >> s;
        n = s.size();
        int k[n], st[n];
        memset(k, 0, sizeof k);
        memset(st, 0, sizeof st);

        lop(n - 4)
        {
          string x = s.substr(i, 4);
          if(x == a)
            k[i]++;
          //cout << x << ' ';
          if(i <= n - 5)
          {
            string y = s.substr(i, 5);
            if(y == b)
              st[i]++;
            //cout << y;
          }
          //cout << endl;
        }

        loopr(i, n - 2, 0)
          st[i] += st[i + 1];

        /*lop(n) cout << k[i] << ' ';
        cout << endl;
        lop(n) cout << st[i] << ' ';*/

        int ans = 0;

        lop(n)
        {
          if(k[i])
          {
            ans += st[i];
          }
        }
        
        Case(t++);
        cout << ans << '\n';
    }

    return 0;
}
