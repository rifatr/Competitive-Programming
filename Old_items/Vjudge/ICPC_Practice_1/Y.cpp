#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

struct Node
{
    int w, v;

    bool operator < (const Node &b) const
    {
        return w < b.w;
    }
};

const int N = 5e3 + 8, inf = 1 << 30;
vector <pair<int, int>> node[N];
int n, dis[N + 1], r, dis2[N + 1];

int dijkstra();

int32_t main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        cin >> n >> r;
        lop(r)
        {
            int u, v, w;
            cin >> u >> v >> w;

            node[u].push_back({v, w});
            node[v].push_back({u, w});
        }

        int ans = dijkstra(), tmp = inf;
        for (auto &z : node[1])
            tmp = min(tmp, dis[n] + (2 * z.second));

        cout << min(ans, tmp) << '\n';
        lop(n + 2) node[i].clear();
    }

    return 0;
}

int dijkstra()
{
    Node nodE;
    priority_queue <Node> q;
    nodE.v = 1, nodE.w = 0;
    q.push(nodE);

    lop(n + 2) dis[i] = dis2[i] = inf;
    dis[1] = 0;

    while (!q.empty())
    {
        auto uu = q.top();
        int u = uu.v;
        q.pop();

        for (auto &vv : node[u])
        {
            int v = vv.first, c = vv.second;

            int d = dis[u] + c;
            // printf("%d %d %d %d\n", u, v, dis[v], dis2[v]);
            if (d < dis[v])
            {
                dis2[v] = min(dis[v], min(dis2[v], min(dis2[u] + c, dis[u] + (3 * c))));
                dis[v] = d;
                nodE.v = v, nodE.w = dis[v] + dis2[v];
                q.push(nodE);
            }

            else if (d > dis[v] and d < dis2[v])
                dis2[v] = d;

            // printf("%d %d %d %d\n", u, v, dis[v], dis2[v]);
        }
    }

    return dis2[n];
}