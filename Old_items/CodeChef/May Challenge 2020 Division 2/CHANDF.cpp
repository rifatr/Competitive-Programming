#include<bits/stdc++.h>

#define ll long long

using namespace std;

void ff(ll x, ll y, ll l, ll r)
{
    ll i;

    for(i = l; i <= r; i++)
    {
        printf("%lld & %lld = %lld\t%lld & %lld = %lld\t",x, i, (x & i), y, i, (y & i));
        cout << "result = " << (x & i) * (y & i) << endl;
    }
}

ll LargestPower2(ll x)
{
    ll i;

    for(i = 1; i <= x / 2; i *= 2)
    {
        x = x | (x >> i);
    }

    return (x + 1) / 2;
}

//ll fun(ll l, ll r)
//{
//    if(l == r)
//        return l;
//
//    ll ans = LargestPower2(r);
//    if(ans <= l)
//    {
//        l = l - ans;
//        r = r - ans;
//
//        return fun(l, r) + ans;
//    }
//
//    ll ans2 = ans * 2;
//
//    if(ans2 - 1 <= r)
//        return ans2 - 1;
//
//    return ans - 1;
//}

ll f(ll x, ll y, ll z)
{
    return ((x & z) * (y & z));
}

void solve(ll x, ll y, ll l, ll r)
{
    ll m = max(x, y);
    if(l == r || m == 0) {
        cout << l << '\n';
        return;
    }

    ll lp2 = LargestPower2(r) - 1;
    if(m > r && lp2 >= l) {
        cout << lp2 << '\n';
        return;
    }
    ll a = f(x, y, m), b = f(x, y, lp2);
    ll ans = a >= b ? m : lp2;

    cout << ans << '\n';

    return;
}

//void solve2(ll x, ll y, ll l, ll r)
//{
//    if(l == r) {
//        cout << l << '\n';
//        return;
//    }
//
//    int i;
//    ll m = max(x, y);
//
//    bitset <64> n(m);
//
//    for(i = 63; i >= 0; i--)
//    {
//        if(n[i] == 1)
//            break;
//    }
//
//    if(i == -1) {
//        cout << l << '\n';
//        return;
//    }
//
//    //const int saiz = i + 1;
//    bitset <i + 1> lp;
//    lp.set();
//    ll lp2 = lp.to_ulong();
//
//    ll a = f(x, y, m), b = f(x, y, lp2);
//    ll ans = a >= b ? m : lp2;
//
//    cout << ans << '\n';
//
//    return;
//
//}

int main()
{
    ll t, x, y, l, r, i, j;

    cin >> t;

    while(t--)
    {
        cin >> x >> y >> l >> r;

        //ff(x, y, l, r);
        solve(x, y, l, r);
    }

    return 0;
}
