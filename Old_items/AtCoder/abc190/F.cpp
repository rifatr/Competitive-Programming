#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

const int N = 3e5 + 6;
int n, a[N], bit[N];

void edit(int pos)
{
    while (pos <= n)
    {
        bit[pos] += 1;
        pos += pos & -pos;
    }
}

ll sum(int pos)
{
    ll s = 0;
    while (pos)
    {
        s += bit[pos];
        pos -= pos & -pos;
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int x, test = 1;

    // cin >> test;

    while (test--)
    {
        cin >> n;
        lop(n)
        {
            cin >> a[i + 1];
            a[i + 1]++;
        }

        ll ans = 0;
        for (int i = n; i; i--)
        {
            ans += sum(a[i] - 1);
            cout << ans << '\n';

            edit(a[i]);
        }

        cout << ans << '\n';


    }

    return 0;
}