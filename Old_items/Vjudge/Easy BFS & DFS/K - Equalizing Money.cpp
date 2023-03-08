#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

#define Case(i) cout << "Case " << int(i) << ": "
#define yes cout << "Yes\n"
#define no cout << "No\n"

#define N 1010

vector <int> adj[N];
set <int> lst;
queue <int> line;
int cash[N], n, m;
ll amm, pp;
bool vis[N], f;

void bfs(int s);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int x, test, t = 1, u, v;

    cin >> test;

    while(test--)
    {
        cin >> n >> m;

        lop(1, n + 1) cin >> cash[i];

        lop(0, m)
        {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        f = 0;
        lop(1, n + 1)
        {
            if(!vis[i])
            {
                amm = pp = 0;

                bfs(i);

                if(amm % pp)
                {
                    f = 1;
                    break;
                }

                else
                    lst.insert(amm / pp);
            }

            if(lst.size() > 1)
            {
                f = 1;
                break;
            }
        }

        Case(t++);
        if(f) no;
        else yes;

        lst.clear();
        lop(0, n + 1)
        {
            adj[i].clear();
            vis[i] = 0;
        }

    }

    return 0;
}

void bfs(int s)
{
    line.push(s);
    vis[s] = pp = 1;
    amm = cash[s];


    while(!line.empty())
    {
        int u = line.front();
        line.pop();
        int saiz = adj[u].size();

        for(int i = 0; i < saiz; i++)
        {
            int v = adj[u][i];

            if(!vis[v])
            {
                line.push(v);
                vis[v] = 1;
                pp++;
                amm += cash[v];
            }
        }
    }
}
