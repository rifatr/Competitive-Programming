#include<bits/stdc++.h>
#include<queue>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "
#define pii pair <int, int>
#define N 1003
#define K 101

vector <int> adj[N];
ll dis[N], n, f, k, city[K];
bool visited[N], have[N];


void bfs(int s);
//void initialize();

int main()
{
//    freopen("F in.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, t = 1, u, v, n, m;

    cin >> test;

    while(test--)
    {
        cin >> k >> n >> m;

        lop(0, k) {
            cin >> city[i];
            dis[city[i]] = have[city[i]] = 1;
        }

        int kk = 0;
        //cout << "kk = " << kk << '\n';

        lop(0, m)
        {
            cin >> u >> v;

            adj[u].push_back(v);
        }

        lop(1, n + 1) {
            if(have[i] == 1) {
                lop(1, n + 1) visited[i] = 0;
                kk++;
                bfs(i);
            }
        }

//        lop(1, n + 1) cout << have[i] << ' ';
//        cout << endl;
//        cout << "kk = " << kk << '\n';
//        lop(1, n + 1) cout << dis[i] << ' ';

        int c = 0;

        lop(1, n + 1) if(dis[i] >= kk) c++;

        Case(t++);
        cout << c << '\n';

        lop(1, n + 1)
        {
            adj[i].clear();
            dis[i] = have[i] = 0;
        }
    }


    return 0;
}

void bfs(int s)
{
//    cout << "came " << s << "\n";
//    lop(1, n + 1) visited[i] = 0;
//    lop(1, n + 1) cout << i << "\t" << visited[i] << '\n';

    queue <int> line;
    line.push(s);
    visited[s] = 1;

    while(!line.empty())
    {
        int u = line.front();
        line.pop();
        int saiz = adj[u].size();

        //cout << u << " " << saiz << endl;

        for(int i = 0; i < saiz; i++)
        {
            int v = adj[u][i];

            if(!visited[v])
            {
                line.push(v);
                visited[v] = 1;
                dis[v]++;

                //printf("%d %d -> %d %d\n", u, v, dis[u], dis[v]);
            }
        }
    }
}

//void initialize()
//{
//    lop(1, n + 1)
//    {
//        adj[i].clear();
//        dis[i] = have[i] = 0;
//    }
//}


