#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

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
    ll n;
    cin >> n;

    ll l = n * (n + 1) / 2;

    if (!l or (l & 1))
    {
        no;
        return ;
    }

    yes;

    l /= 2;

    vector <int> a[2];

    for (int i = n; i; i--)
    {
        if (l - i >= 0)
            a[0].push_back(i), l -= i;
        else
            a[1].push_back(i);
    }

    lop(2)
    {
        cout <<  a[i].size() << '\n';
        loop(j, 0, a[i].size())
        cout << a[i][j] << ' ';
        cout << '\n';
    }

    return;
}