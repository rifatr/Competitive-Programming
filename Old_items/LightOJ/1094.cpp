#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "
#define pii pair <int, int>
#define N 30009

struct Node
{
    int c, w;
};

vector <Node> tree[N];
int dis[N], n, f;
bool visited[N];


void bfs(int s);

int main()
{
    //freopen("E in.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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

            //printf("%d %d %d -> %d %d %d\n", u, pp.c, pp.w, v, qq.c, qq.w);
        }

        //lop(0, n) lopj(0, tree[i].size()) printf("%d %d %d -> %d\n", i, tree[i][j].c, tree[i][j].w, (int)tree[i].size());

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
        lop(0, n) mx = max(mx, dis[i]);

        cout << mx << '\n';

        lop(0, N) tree[i].clear();
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

                //cout << v.c << ' ' << dis[v.c] << '\n';
            }
        }
    }
}
