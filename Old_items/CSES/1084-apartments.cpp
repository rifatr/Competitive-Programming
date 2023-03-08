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
    ll n, m, k;
    cin >> n >> m >> k;

    ll a[n], b[m + m], ans = 0;
    lop(n) cin >> a[i];
    lop(m) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    bool taken[m];
    memset(taken, 0, sizeof taken);

    int j = 0;
    lop(n)
    {
        for (; j < m; j++)
        {
            if (b[j] >= a[i] - k and b[j] <= a[i] + k)
            {
                ans++;
                j++;
                break;
            }
            else if (b[j] > a[i] + k)
                break;
            // cout << b[j] << ' ' << a[i] << '\n';
        }
    }

    cout << ans << '\n';

    return;
}