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

bool ispal(ll n)
{
    ll x = 0, k = n;

    while(k)
    {
        int p = k % 10;
        x = (x * 10) + p;
        k /= 10;
    }


    return x == n;
}

ll rev(ll k)
{
    ll x = 0;

    while(k)
    {
        int p = k % 10;
        x = (x * 10) + p;
        k /= 10;
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tt, n, k;
    vector <int> v1, v2, test;

    cin >> tt;

    while(tt--)
    {
        cin >> n;

        k = n;
        int c = 0;

        while(!ispal(k))
        {
            ll x = rev(k);
            k += x;
            c++;
        }

        cout << c << " " << k << '\n';
    }



    return 0;
}

