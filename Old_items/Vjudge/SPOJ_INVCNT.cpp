#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

const int N = 2e5 + 6;
int n, a[N], bit[N];
multimap <int, int> cnt;

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

    int x, test;

    cin >> test;

    while (test--)
    {
        cin >> n;
        lop(n)
        {
            cin >> x;
            cnt.insert({x, i + 1});
        }

        int k = 1;
        for (auto &it : cnt)
            a[it.second] = k++;

        ll ans = 0;
        for (int i = n; i; i--)
        {
            ans += sum(a[i] - 1);
            edit(a[i]);
        }

        cout << ans << '\n';
        cnt.clear();
        lop(n + 3) bit[i] = 0;
    }

    return 0;
}