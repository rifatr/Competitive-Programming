#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

#define ff first
#define ss second

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
    int n, m;
    cin >> n >> m;

    int t[m];
    map <int, int> h;
    h[0] = 0;
    lop(n)
    {
        int p; cin >> p;
        h[p]++;
    }
    lop(m) cin >> t[i];

    lop(m)
    {
        auto it = h.upper_bound(t[i]);
        it--;

        if (it -> first == 0)
            cout << -1 << '\n';

        else
        {
            cout << it -> first << '\n';
            h[it -> first]--;
            if (it -> second == 0)
                h.erase(it);
        }
    }

    return;
}