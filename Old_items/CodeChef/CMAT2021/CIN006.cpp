#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

void solve();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int test = 1;

    cin >> test;

    while (test--)
    {
        solve();
    }

    return 0;
}

void solve()
{
    ll x, y, z;
    cin >> x >> y >> z;
    // if (x < y) swap(x, y);

    ll a1 = (x / z) + (y / z);

    ll p1, q1, p2, q2, ans = 0;
    p1 = x % z, p2 = y % z;
    q1 = (((x + z - 1) / z) * z) - x;
    q2 = (((y + z - 1) / z) * z) - y;

    if (q1 < q2 and q1 <= p2)
    {
        x += q1;
        y -= q1;
        ans = q1;
    }
    else if (q1 >= q2 and q2 <= p1)
    {
        y += q2;
        x -= q2;
        ans = q2;
    }

    // printf("%lld %lld %lld %lld %lld %lld\n", x, y, p1, p2, q1, q2);

    ll a2 = (x / z) + (y / z);
    if (a2 <= a1)
        ans = 0, a2 = a1;

    cout << a2 << ' ' << ans << '\n';

    return;
}