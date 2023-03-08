#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ":\n"
#define pii pair <int, int>
#define N 30010

struct Node
{
    int c, w;
};

vector <Node> tree[N];
int dis[N], n, f, dis2[N];
bool visited[N];


void bfs(int s);
void bfs2(int s);

int main()
{
    int test, t = 1, u, v, wt;

    cin >> test;

    while(test--)
    {
        cin >> n;

        Node pp, qq;

        lop(0, n - 1)
        {
            cin >> u >> v >> wt;

            pp.c = v;
            pp.w = wt;
            tree[u].push_back(pp);

            qq.c = u;
            qq.w = wt;
            tree[v].push_back(qq);
        }

        Case(t++);

        bfs(0);

        int mx = 0;
        lop(0, n)
        {
            if(dis[i] > mx)
            {
                mx = dis[i];
                f = i;
            }
        }

        bfs(f);

        mx = 0;
        lop(0, n)
        {
            if(dis[i] > mx)
            {
                mx = dis[i];
                f = i;
            }
        }

        bfs2(f);

        lop(0, n) cout << max(dis[i], dis2[i]) << '\n';

        lop(0, n) tree[i].clear();
    }


    return 0;
}

void bfs(int s)
{
    lop(0, n) visited[i] = dis[i] = 0;

    queue <int> line;
    line.push(s);
    visited[s] = 1;
    dis[s] = 0;

    //cout << s << ' ';

    while(!line.empty())
    {
        int u = line.front();
        line.pop();
        int saiz = tree[u].size();

        for(int i = 0; i < saiz; i++)
        {
            Node v = tree[u][i];

            if(!visited[v.c])
            {
                line.push(v.c);
                visited[v.c] = 1;
                dis[v.c] = dis[u] + v.w;

                //cout << u << " " << v.c << " " << dis[u] << " " << dis[v.c] << endl;
            }
        }
    }
}


void bfs2(int s)
{
    lop(0, n) visited[i] = dis2[i] = 0;

    queue <int> line;
    line.push(s);
    visited[s] = 1;
    dis2[s] = 0;

    while(!line.empty())
    {
        int u = line.front();
        line.pop();
        int saiz = tree[u].size();

        for(int i = 0; i < saiz; i++)
        {
            Node v = tree[u][i];

            if(!visited[v.c])
            {
                line.push(v.c);
                visited[v.c] = 1;
                dis2[v.c] = dis2[u] + v.w;

                //cout << u << " " << v.c << " " << dis2[u] << " " << dis2[v.c] << endl;
            }
        }
    }
}
