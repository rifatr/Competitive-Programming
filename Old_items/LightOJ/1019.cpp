#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int N = 104, inf = 1 << 30;
vector <pair<int, int>> node[N];
int n, m, dis[N];

void dijkstra()
{
    priority_queue <int> q;
    q.push(1);
    //visited[1] = true;
    dis[1] = 0;

    while (!q.empty())
    {
        int u = q.top();
        q.pop();

        for (int i = 0; i < node[u].size(); i++)
        {
            auto v = node[u][i];
            if (dis[u] + v.second < dis[v.first]) {
                //visited[v.first] = true;
                dis[v.first] = dis[u] + v.second;
                q.push(v.first);
            }
        }
    }
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        cin >> n >> m;
        lop(m)
        {
            int u, v, w;
            cin >> u >> v >> w;

            node[u].push_back({v, w});
            node[v].push_back({u, w});
        }
        lop(n + 2) dis[i] = inf;

        dijkstra();

        if (dis[n] == inf)
            cout << "Impossible\n";
        else
            cout << dis[n] << '\n';

        lop(n + 2) node[i].clear();
    }

    return 0;
}