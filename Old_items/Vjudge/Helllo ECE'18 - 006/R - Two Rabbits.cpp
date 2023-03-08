#include<bits/stdc++.h>

#define ll long long
#define lop(n) for(int i = 0; i < n; i++)
#define lop1(n) for(int i = 1; i <= n; i++)
#define lopj(n) for(int j = i; j < n; j++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mod 1000000007
const long long inf = 999999999999;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tt, x, y, a, b;

    cin >> tt;

    while(tt--)
    {
        cin >> x >> y >> a >> b;

        if((y - x) % (a + b))
            cout << -1 << '\n';
        else
            cout << ((y - x) / (a + b)) << '\n';
    }

    return 0;
}

