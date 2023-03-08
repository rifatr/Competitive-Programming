#include<bits/stdc++.h>

#define pb push_back
#define lop(n) for(int i = 0; i < n; i++)
#define lop2(n) for(int j = 0; j < n; j++)
#define N 205

using namespace std;

vector <int> adjmat[N + 1];
bool visited[N + 1];

bool bfs_bicolor(int n)
{
    queue <int> Q;

    Q.push(0);
    visited[0] = color[0] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int saiz = adjmat[u].size();

        lop(saiz)
        {
            int v = adjmat[u][i];

            if(color[v] == 0)
            {
                Q.push(v);

                if(color[u] == 1)
                    color[v] = 2;
                else
                    color[v] = 1;
            }

            if(color[u] == color[v])
                return 1;
        }
    }

    return 0;
}

int main()
{
    int n, e, s, u, v;

    while(scanf("%d", &n) && n && scanf("%d", &e))
    {
        lop(e)
        {
            scanf("%d %d", &u, &v);

            adjmat[u].pb(v);
            adjmat[v].pb(u);
        }

        bool f = bfs_bicolor(0);

        string res = "BICOLORABLE.";

        if(f)
            res = "NOT BICOLORABLE.";

        cout << res << '\n';

        lop(n) adjmat[i].clear();
        memset(color, 0, sizeof(color));
    }

    return 0;
}

