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

double eqn(double L)
{
    double Q = 1 - (0.25 * acos(-1.0));
    return (L * L * Q) + (1.42699081698 * L);
}

int main()
{
    fastio;

    int tt;

    cin >> tt;

    while(tt--)
    {
        double A;

        cin >> A;

        double l = A / ((3 / 4.0) - (PI / 8));

        /*double l = 0.0, h = 1000000000000000000.0, mid;
        int k = 90;

        while(k--)
        {
            mid = (l + h) / 2.0;

            double L = eqn(mid);
            //printf("%lf %lf %lf %lf\n", l, h, mid, L);

            if(L > A)
                h = mid;
            else
                l = mid;
        }*/

        cout << fixed;
        cout << setprecision(10) << sqrt(l) << '\n';
    }

    return 0;
}


