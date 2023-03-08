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
#define lopr(a, n)      for(int k = a; k < n; k++)
#define lrev(n, a)      for(int i = n; i >= a; i--)

#define all(x)          x.begin(), x.end()
#define mem(a, b)       memset(a, b, sizeof(a))

#define vin             vector <int>
#define vll             vector <ll>
#define vst             vector <string>
#define pll             pair <ll, ll>
#define pss             pair <string, string>
#define vpll            vector <pll>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             1000000007
#define PI              acos(-1.0)
#define inf             999999999999
#define N               21

using namespace std;

ll fact[N];
bool f[N];

void facto()
{
    fact[0] = 1;

    lopr(1, N)
        fact[k] = k * fact[k - 1];
}

int main()
{
    //fastio;

    facto();

    lop(N) cout << i << " -> " << fact[i] << '\n';

    int tt, t = 1;
    ll n;
    vin v;

    cin >> tt;

    while(tt--)
    {
        cin >> n;

        mem(f, 0);
        int x = n;

        while(n > 0 and x)
        {
            x = lower_bound(fact, fact + N, n) - fact;

            if(fact[x] > n)
                x--;

            while(f[x] and x--);

            v.pb(x);
            n -= fact[x];
            f[x] = 1;
        }

        Case(t++);

        if(n != 0)
        {
            cout << "impossible\n";
        }

        else
        {
            reverse(all(v));
            int saiz = v.size();
            lop(saiz)
            {
                cout << v[i] << '!';
                if(i < saiz - 1)
                    cout << '+';
                else
                    cout << '\n';
            }
        }

        v.clear();
    }

    return 0;
}
