#include<bits/stdc++.h>

#define pb push_back
#define lop(n) for(int i = 0; i < n; i++)
#define lop2(n) for(int j = 0; j < n; j++)
#define N 205

using namespace std;

vector <int> adjmat[N + 1];
int color[N + 1];
bool visited[N + 1];

void bfs_bicolor(int n)
{
    lop(n) color[i] = visited[i] = 0;

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

            if(visited[v] == 0) {
                visited[v] = 1;
                Q.push(v);
            }

            if(color[v] == 0)
            {
                if(color[u] == 1)
                    color[v] = 2;
                else
                    color[v] = 1;
            }
        }
    }

}

int main()
{
    int n, e, s, u, v;

    while(scanf("%d", &n) && n && scanf("%d", &e))
    {
        lop(n) adjmat[i].clear();

        lop(e)
        {
            scanf("%d %d", &u, &v);

            adjmat[u].pb(v);
            adjmat[v].pb(u);
        }

        bfs_bicolor(n);

        string res = "BICOLORABLE.";

        lop(n)
        {
            int saiz = adjmat[i].size();
//            cout << "Node = " << i << " Color = " << color[i] << '\n';

            lop2(saiz)
            {
                int v = adjmat[i][j];
//                cout << "ADJNode = " << v << " Color = " << color[v] << '\n';

                if(color[i] == color[v])
                {
                    res = "NOT BICOLORABLE.";
                    break;
                }
            }

            if(res == "NOT BICOLORABLE.")
                break;
        }

        cout << res << '\n';
    }

    return 0;
}
