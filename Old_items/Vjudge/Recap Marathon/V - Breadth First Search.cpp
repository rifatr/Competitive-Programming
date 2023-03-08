#include<bits/stdc++.h>

using namespace std;

vector <int> adj[105];
int level[105];
bool visited[105];

void bfs()
{
    for(int i = 0; i < 105; i++)
        level[i] = -1;

    queue <int> q;
    q.push(1);
    visited[1] = true;
    level[1] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(!visited[v]) {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int node, vertice, edge, vertex, u, v, i, j;

    cin >> node;

    for(i = 0; i < node; i++)
    {
        cin >> vertice >> edge;
        for(j = 0; j < edge; j++) {
            cin >> vertex;
            adj[vertice].push_back(vertex);
        }
    }

    bfs();

    for(i = 1; i <= node; i++) {
        cout << i << " " << level[i] << endl;
    }

    return 0;
}
