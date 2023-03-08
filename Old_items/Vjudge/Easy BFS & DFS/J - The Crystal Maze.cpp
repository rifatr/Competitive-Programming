#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ":\n"

#define pii pair <int, int>
#define ff first
#define ss second
#define mp make_pair

#define N 502

char grid[N][N];
int cnt[N][N], n, m, q, cc, u, v;
bool vis[N][N];
queue <pii> lst;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y);
bool valid(int x, int y);
void enlst();
void mem();

int main()
{
    //freopen("J in.txt", "r", stdin);

    int x, test, t = 1;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d %d", &n, &m, &q);

        lop(0, n)
        {
            scanf("%s", &grid[i]);
            lopj(0, m)
            {
                //scanf("%s", &grid[i]);

                if(grid[i][j] == '#')
                    vis[i][j] = 1;
            }
        }

        lop(0, n) lopj(0, m)
        {
            if(vis[i][j]) continue;

            cc = 0;
            dfs(i, j);
            enlst();
        }

        Case(t++);
        lop(0, q)
        {
            scanf("%d %d", &u, &v);

            printf("%d\n", cnt[u - 1][v - 1]);
        }

        mem();
    }

    return 0;
}

bool valid(int x, int y)
{
    return x < 0 or y < 0 or x >= n or y >= m;
}

void dfs(int x, int y)
{
    if(vis[x][y] or valid(x, y))
        return;

    if(grid[x][y] == 'C')
        cc++;

    vis[x][y] = 1;

    lst.push(mp(x, y));

    lop(0, 4)
    dfs(x + dx[i], y + dy[i]);

}

void enlst()
{
    while(!lst.empty())
    {
        pii x = lst.front();
        lst.pop();

        cnt[x.ff][x.ss] = cc;
    }
}

void mem()
{
    lop(0, n) lopj(0, m)
    vis[i][j] = cnt[i][j] = 0;
}
