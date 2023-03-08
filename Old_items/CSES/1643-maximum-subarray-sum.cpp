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

    // cin >> test;

    while (test--)
    {
        solve();
    }

    return 0;
}

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    lop(n) cin >> a[i];

    ll ans = -1e18, sum = 0;
    lop(n)
    {
        sum += a[i];
        ans = max(ans, sum);
        sum = max(0LL, sum);
    }

    cout << ans << '\n';

    return;
}