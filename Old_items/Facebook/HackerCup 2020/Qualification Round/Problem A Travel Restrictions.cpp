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
#define Case(i)         cout << "Case #" << int(i) << ":\n"

#define lop(n)          for(int i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)
#define lopr(a, n)      for(int k = a; k < n; k++)
#define lrev(n, a)      for(int k = n; k > a; k--)

#define all(x)          x.begin(), x.end()
#define mem(a, b)       memset(a, b, sizeof(a))

#define vin             vector <int>
#define vll             vector <ll>
#define vst             vector <string>
#define pll             pair <ll, ll>
#define pss             pair <string, string>
#define vpll            vector <pll>

#define fread           freopen("travel_restrictions_input.txt", "r", stdin)
#define fwrite          freopen("travel_restrictions_output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             1000000007
#define PI              acos(-1.0)
#define inf             999999999999


using namespace std;


int main()
{
    fastio;
    //fread;
    //fwrite;

    int tt, n, t = 1;

    cin >> tt;

    while(tt--)
    {
        cin >> n;

        char in[n], out[n];

        lop(n) cin >> in[i];
        lop(n) cin >> out[i];

        Case(t++);

        lop(n)
        {
            lopj(n)
            {
                if(i == j)
                {
                    cout << 'Y';
                    continue;
                }

                bool f = 1;

                if(i < j)
                {
                    lopr(i, j)
                    {
                        if(out[k] == 'N' or in[k + 1] == 'N')
                        {
                            f = 0;
                            break;
                        }
                    }
                }

                else
                {
                    lrev(i, j)
                    {
                        if(out[k] == 'N' or in[k - 1] == 'N')
                        {
                            f = 0;
                            break;
                        }
                    }
                }

                if(f)
                    cout << 'Y';
                else
                    cout << 'N';
            }
            cout << '\n';
        }
    }

    return 0;
}

