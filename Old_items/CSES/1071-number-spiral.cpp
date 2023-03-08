#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

ll sq(ll x)
{
    return x * x;
}

ll solve();

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
        cout <<  solve() << '\n';
    }

    return 0;
}

ll solve()
{
    ll x, y;
    cin >> x >> y;

    if (y <= x)
    {
        if (x & 1)
            return sq(x - 1) + y;

        return sq(x) - y + 1;
    }

    if (y & 1)
        return sq(y) - x + 1;

    return sq(y - 1) + x;

}