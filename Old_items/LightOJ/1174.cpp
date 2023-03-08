#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "

vector <int> building[101];
bool bombed[101], f;
int n, start_dis[101], end_dis[101];


void bombing_bfs(int s);
void initialize();

int main()
{
    //freopen("C in.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, test, u, v, s, e, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> n >> r;

        lop(0, r)
        {
            cin >> u >> v;

            building[u].push_back(v);
            building[v].push_back(u);
        }

        cin >> s >> e;

        bombing_bfs(s);
        f = 1;
        bombing_bfs(e);

        int taim = 0;

        lop(0, n) {
            //cout << start_dis[i] << ' ' << end_dis[i] << '\n';
            taim = max(taim, start_dis[i] + end_dis[i]);
        }

        Case(t++);
        cout << taim << '\n';

        initialize();
    }

    return 0;
}

void bombing_bfs(int s)
{
    lop(0, n) bombed[i] = 0;

    queue <int> line;
    line.push(s);
    bombed[s] = 1;
    if(f) end_dis[s] = 0;
    else start_dis[s] = 0;

    while(!line.empty())
    {
        int u = line.front();
        line.pop();
        int saiz = building[u].size();

        for(int i = 0; i < saiz; i++)
        {
            int v = building[u][i];

            if(!bombed[v])
            {
                line.push(v);
                bombed[v] = 1;
                if(f) end_dis[v] = end_dis[u] + 1;
                else start_dis[v] = start_dis[u] + 1;

            }
        }
    }
}

void initialize()
{
    lop(0, n) building[i].clear();
    f = 0;
}
