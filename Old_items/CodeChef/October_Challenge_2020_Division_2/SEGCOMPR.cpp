#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define mod 998244353

const int N = 3e5+5;
int a[N], n;

int LargestPower2(int x)
{
    if(x < 2LL) return 0LL;

    int i;

    for(i = 1; i <= x / 2; i *= 2)
    {
        x = x | (x >> i);
    }

    return (x + 1) / 2;
}

int f(int l, int r)
{
    if(l - r == 0)
        return a[l];

    vector <int> v, v2;

    loop(i, l, r + 1)
    {
        if(a[i] > 1 and !(a[i] & (a[i] - 1)))
            v2.push_back(a[i]);
        else
            v.push_back(a[i]);
    }

    int s = v.size(), ss = v2.size();

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    lop(s - 1) if(v[i] == v[i + 1]) v[i] = v[i + 1] = 0;
    sort(v.begin(), v.end());
    lop(ss - 1) if(v2[i] == v2[i + 1]) v2[i] = v2[i + 1] = 0;
    sort(v2.begin(), v2.end());

    /*if(!ss)
        return LargestPower2(v[s - 1]);
    if(!s)
        return v2[ss - 1];*/

    int i, j;
    for(i = s - 1, j = ss - 1; i > 0 and j >= 0; i--)
    {
        if(v[i] == v[i - 1])
        {
            v[i - 1] = 0;
            continue;
        }

        ll p = LargestPower2(v[i] ^ v[i - 1]);

        if(p > v2[j])
            v[i - 1] = p;
        else if(p == v2[j])
            v[i - 1] = 0, j--;
        else
            v[i - 1] = v2[j], j--;

    }

    if(j < 0 and i == 0)
        return v[i];

    if(j < 0 and i > 0)
        return LargestPower2(v[i] ^ v[i - 1]);

    cout << i << ' ' << j << ' ' << v[i] << ' ' << v2[j] << endl;

    return LargestPower2(v[i] ^ v2[j]);
}

int main()
{
    cin >> n;

    lop(n) cin >> a[i];

    ll ans = 0;

    lop(n)
    {
        loop(j, i + 1, n)
        {  
            ll x = f(i, j);
            cout << i << ' ' << j << ' ' << x << endl;
            ans = ((ans % mod) + (ll) (x % mod)) % mod;
        }

    }

    cout << ans << '\n';

    return 0;
}
