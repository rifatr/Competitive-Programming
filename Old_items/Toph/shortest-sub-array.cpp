#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

const int N = 5e5 + 9;
ll a[N], bit[N];
int q, n;

string updt = "Update";

void edit(int p, ll x)
{
    while (p <= n)
    {
        bit[p] += x;
        p += p & -p;
    }
}

ll sum(int p)
{
    ll s = 0;
    while (p)
    {
        s += bit[p];
        p -= p & -p;
    }

    return s;
}

int solve(int l, ll x)
{
    ll left = sum(l - 1);
    int lo = 1, hi = n, mid, ans = hi + 3;

    // cout << l << ' ' << x << ' ' << left << '\n';
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;

        ll right = sum(mid);
        if (right - left < x)
            lo = mid + 1;
        else
        {
            hi = mid - 1;
            ans = min(ans, mid);
        }
        // cout << lo << ' ' << hi << ' ' << mid << ' ' << right << '\n';
    }

    return ans > n ? -1 : ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, y;
    string s;

    cin >> n >> q;
    lop(n)
    {
        cin >> a[i + 1];
        edit(i + 1, a[i + 1]);
    }

    // lop(n) cout << sum(i + 1) << '\n';

    while (q--)
    {
        cin >> s >> x >> y;

        if (s == updt)
        {
            edit(x, -a[x]);
            a[x] = y;
            edit(x, a[x]);
        }
        else
            cout << solve(x, y) << '\n';
    }

    return 0;
}