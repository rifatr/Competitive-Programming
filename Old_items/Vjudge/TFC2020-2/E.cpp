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

  int tt, n;

  cin >> tt;

  while (tt--)
  {
    string s;
    int k;
    cin >> s >> k;

    int n = s.size(), ans = 0;
    int dis[n + 2] = {0}, fq[26][n + 2], vis[26] = {0};
    mem0(fq);

    lop(n)
    {
        int x = s[i] - 'a';
//        dis[i + 1] = dis[i] + !vis[x];
//        vis[x] = 1;

        lopj(26)
        {
            fq[j][i + 1] = fq[j][i] + (j + 'a' == s[i]);
        }
    }

    lop(n)
    {
        loop(j, i, n)
        {
            bool f = 1;
            int c = 0, x = fq[s[i] - 'a'][j + 1] - fq[s[i] - 'a'][i];
//            if(dis[j + 1] - dis[i] < k)
//                f = 0;

            loop(p, 0, 26)
            {
                int y = fq[p][j + 1] - fq[p][i];
                if(y) {
                    c++;

                    if(x != y) {
                        f = 0;
                        break;
                    }
                }
            }

            ans += (f and c >= k);
        }
    }

//    lop(26)
//    {
//        lopj(n + 1) cout << fq[i][j] << ' ';
//        cout << '\n';
//    }

    //lop(n + 1) cout << dis[i] << ' ';
    cout << ans << '\n';
  }

  return 0;
}

