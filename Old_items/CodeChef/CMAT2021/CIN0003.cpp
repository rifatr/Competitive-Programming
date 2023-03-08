#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

const int N = 1e4 + 3, M = 1e3 + 5;

int n, m;
vector <int> edge[N];
bool vis[N];

void dfs(int v)
{
    if (vis[v])
        return;
    vis[v] = 1;

    for (int &z : edge[v])
        dfs(z);
}

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
    ll a, b;
    cin >> n >> m;
    cin >> a >> b;

    lop(m)
    {
        int u, v;
        cin >> u >> v;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int d = 0;
    lop(n)
    {
        int u = i + 1;
        if (!vis[u])
        {
            dfs(u);
            d++;
        }
    }

    ll p, q;
    p = ((d - 1) * b) + a;
    q = a * d;

    // cout << p << ' ' << q << ' ' << d << '\n';

    cout << min(p, q) << '\n';

    return;
}