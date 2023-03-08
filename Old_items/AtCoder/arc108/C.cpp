#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"



const int N = 2e5 + 5;
vector<pair <int, int>> node[N];;
bool vis[N];
int n, m, num[N];

void dfs(int x, int p, int q)
{
    if (vis[x]) return;

    vis[x] = 1;
    if (p == q)
        num[x] = ((p + 1) % n) + 1;
    else
        num[x] = q;

    for (auto &z : node[x])
        dfs(z.first, num[x], z.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    lop(m)
    {
        int u, v, c;
        cin >> u >> v >> c;

        node[u].push_back({v, c});
        node[v].push_back({u, c});
    }

    dfs(1, 0, 0);

    lop(n)
    {
        if (!vis[i + 1])
        {
            cout << "NO\n";
            return 0;
        }
    }

    lop(n) cout << num[i + 1] << '\n';

    return 0;
}
