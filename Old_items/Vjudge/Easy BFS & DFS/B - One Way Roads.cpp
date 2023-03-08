#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

#define yes cout << "Suspicious bugs found!\n"
#define no cout << "No suspicious bugs found!\n"
#define Case(i) cout << "Scenario #" << int(i) << ":\n"

#define N 110

vector <int> adj[N], cost[N];
int n, f;
bool have[N];

bool bfs(int s);
void initilize();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, test, m, u, v, t = 1, w;

    cin >> test;

    while(test--)
    {
        cin >> n;

        lop(0, m)
        {
            cin >> u >> v >> w;

            adj[u].push_back(v);
            cost[u].push_back(w);
        }

        lop(1, n + 1)
        {
            if(adj[i] == 2)
            {
                lopj(0, 2)
                {
                    x = adj[i][j];

                }
            }
        }

        f = 0;
        lop(1, n + 1)
        {
            if(!color[i])
                f = bfs(i);

            if(f) break;
        }

        Case(t++);
        f == 0 ? no : yes;

        initilize();
    }

    return 0;
}

bool bfs(int s)
{
    queue <int> Q;
    Q.push(s);
    color[s] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int saiz = bug[u].size();

        lop(0, saiz)
        {
            int v = bug[u][i];

            if(!color[v])
            {
                Q.push(v);

                color[v] = (color[u] == 1 ? 2 : 1);
            }

            if(color[u] == color[v])
                return true;
        }
    }

    return false;
}
void initilize()
{
    lop(1, n + 1)
    {
        bug[i].clear();
        color[i] = 0;
    }
}
