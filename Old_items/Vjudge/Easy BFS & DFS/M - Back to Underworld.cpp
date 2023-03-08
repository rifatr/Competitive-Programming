#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "

#define N 20010

vector <int> adj[N];
int color[N], lykan, vampire; // 0 -> not fighter, 1 -> lykan, 2 -> vampire

void bfs(int s);

int main()
{
    //freopen("M in.txt", "r", stdin);

    int test, t = 1, u, v, n;

    cin >> test;

    while(test--)
    {
        cin >> n;

        int mx = 0;

        lop(0, n)
        {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);

            mx = max(mx, max(u, v));
        }

        int res = 0;

        lop(1, mx + 1)
        {
            int x = adj[i].size();

            lykan = vampire = 0;
            if(x and !color[i])
                bfs(i);

            //cout << lykan << " " << vampire << '\n';
            res += max(lykan, vampire);
        }

        Case(t++);
        cout << res << '\n';

        lop(1, mx + 1)
        {
            adj[i].clear();
            color[i] = 0;
        }

    }

    return 0;
}

void bfs(int s)
{
    queue <int> Q;
    Q.push(s);
    color[s] = 1;
    lykan++;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int saiz = adj[u].size();

        lop(0, saiz)
        {
            int v = adj[u][i];

            if(!color[v])
            {
                Q.push(v);

                if(color[u] == 1)
                {
                    color[v] = 2;
                    vampire++;
                }
                else
                {
                    color[v] = 1;
                    lykan++;
                }
            }
        }
    }
}
