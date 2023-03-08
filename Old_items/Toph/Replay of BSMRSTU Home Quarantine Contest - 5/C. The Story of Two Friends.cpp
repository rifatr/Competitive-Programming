#include<bits/stdc++.h>

#define ll long long
#define scan(a) scanf("%d", &a)
#define scanl(a) scanf("%lld", &a)
#define scand(a) scanf("%lf", &a)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scand2(a, b) scanf("%lf %lf", &a, &b)
#define lop(n) for(int i = 0; i < n; i++)
#define lop1(n) for(int i = 1; i <= n; i++)
#define lopj(n) for(int j = 0; j < n; j++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mod 1000000007
const long long inf = 999999999999;

using namespace std;

void OJ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //OJ();

    ll tt, n, a, b, c, x, y, p, q, o, lcm3;

    cin >> tt;

    while(tt--)
    {
        cin >> n >> a >> b >> c;

        x = min(a, b); y = max(a, b);

        p = n / x - (n / ((c * x) / __gcd(c, x)));

        q = n / y - (n / ((x * y) / __gcd(y, x)));
        //cout << "lcm = " << (n / ((c * y) / __gcd(c, x)))) << '\n';
        q -= (n / ((c * y) / __gcd(c, y)));
        //cout << "q = " << q << '\n';

        lcm3 = (x * y) / __gcd(x, y);
        lcm3 = (lcm3 * c) / __gcd(lcm3, c);
        //cout << "lcm = " << lcm3 << '\n';
        q += (n / lcm3);

        //cout << p << " " << q << " " << p + q << '\n';
        cout << p + q << '\n';
    }



    return 0;
}

