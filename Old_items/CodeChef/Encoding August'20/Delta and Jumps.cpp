#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

#define N 1005

vector <int> shop[N];
bool vis[N];
queue <int> Q;

void bfs(int s);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    ll x, test, n, m, mar, u, v;

    cin >> test;

    while(test--)
    {
        cin >> n >> m;

        lop(0, m)
        {
            cin >> u >> v;

            shop[u].push_back(v);
            shop[v].push_back(u);
        }

        mar = 0;
        lop(0, n)
        {
            if(!vis[i])
            {
                bfs(i);
                mar++;
            }
        }

        cout << mar << '\n';

        lop(0, n)
            shop[i].clear(), vis[i] = 0;
    }

    return 0;
}


void bfs(int s)
{
    vis[s] = 1;

    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int saiz = shop[u].size();

        lop(0, saiz)
        {
            int v = shop[u][i];

            if(!vis[v])
            {
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
}
