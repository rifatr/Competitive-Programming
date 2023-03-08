#include<bits/stdc++.h>

#define ll              unsigned long long
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
#define bug             cout << "here\n"
#define Case(i)         cout << "Case " << int(i) << ": "

#define lop(n)          for(int i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)
#define lopr(a, n)      for(int k = a; k < n; k += 2)
#define lrev(n, a)      for(int i = n; i >= a; i--)

#define all(x)          x.begin(), x.end()
#define mem(a, b)       memset(a, b, sizeof(a))

#define vin             vector <int>
#define vll             vector <ll>
#define vst             vector <string>
#define pll             pair <ll, ll>
#define pss             pair <string, string>
#define mll             map  <ll, ll>
#define vpll            vector <pll>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             1000000007
#define PI              acos(-1.0)
#define inf             999999999999999999


using namespace std;

mll bpf, npf;

void pf(ll x)
{
    int i = 0;

    while(!(x % 2))
    {
        x /= 2;
        bpf[2]++;
    }

    lopr(3, sqrt(x * 1.0) + 1)
    {
        while(!(x % k))
        {
            x /= k;
            bpf[k]++;
        }
    }

    if(x != 1)
        bpf[x]++;
}

int main()
{
    ll n, b;

    cin >> n >> b;

    if(n == 1)
    {
        cout << 0 << '\n';

        return 0;
    }

    pf(b);

//    for(auto i = bpf.begin(); i != bpf.end(); i++)
//        cout << i -> ff << " - " << i -> ss << "\n";

    for(auto i = bpf.begin(); i != bpf.end(); i++)
    {
        ll z = i -> ff;
        ll x = n, p = z;

        while(z <= x)
        {
            npf[p] += x / z;
            //cout << z << ' ' << npf[p] << '\n';

            if(z > x / p)
                break;

            z *= p;
        }

        //cout << p << " " << npf[p] << " " << i -> ss << '\n';
        //bug;

        npf[p] /= i -> ss;
    }

    ll ans = inf;

    for(auto i = npf.begin(); i != npf.end(); i++)
        ans = min(ans, i -> ss);

//    for(auto i = npf.begin(); i != npf.end(); i++)
//        cout << i -> ff << " - " << i -> ss << '\n';

    cout << ans << '\n';

    return 0;
}

//594703138034372316 960179812013
