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
#define pll             pair <int, int>
#define pss             pair <string, string>
#define vpll            vector <pll>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             1000000007
#define PI              acos(-1.0)
#define inf             999999999999


using namespace std;


int main()
{
    fastio;

    int n;
    string s;

    cin >> n >> s;

    pll lst[n + 1], pp = {0, 0};

    //lst[0] = pp;

    lop(n)
    {
        pp.ff += s[i] == 'W';
        pp.ss += s[i] == 'R';

        lst[i] = pp;
    }

    int dr = 0;

    lrev(n - 1, 0)
    {
        if(lst[i].ff - dr <= 0 or lst[i].ff == 0)
            break;

        if(s[i] == 'R')
        {
            dr++;
        }
    }

    if(lst[n - 1].ff == 0)
        cout << 0 << endl;

    else if(lst[n - 1].ss == 0)
        cout << 0 << endl;

    else
        cout << dr << endl;

//    int w = 0, r = 0, rr = 0, ww = 0;
//
//    lop(n)
//    {
//        w += s[i] == 'W';
//        r += s[i] == 'R';
//
//        if(r and i < n - 1 and s[i + 1] == 'W')
//        {
//            rr = ww = 0;
//            lopr(i + 1, n) {
//                ww += s[k] == 'W';
//                rr += s[k] == 'R';
//            }
//
//            break;
//        }
//    }

   // cout << r << ' ' << rr << ' ' << w << ' ' << ww << '\n';

//    if(w + ww == 0)
//        cout << 0 << endl;
//
//    else if(r == 0)
//        cout << 1 << endl;
//
//    else if(w <= rr)
//        cout << rr << endl;
//
//    else
//        cout << min(w, r + rr) << endl;
//main();
    return 0;
}

