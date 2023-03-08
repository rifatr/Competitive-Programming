#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "

#define pii pair <int, int>
#define ff first
#define ss second
#define mp make_pair

#define N 12

char grid[N][N];
int n, k, dis[N][N];
bool vis[N][N];

int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y)
{
    return x < 0 or y < 0 or x >= n or y >= n;
}

int bfs(int x, int y, char t)
{
    memset(vis, 0, sizeof vis);
    memset(dis, 0, sizeof dis);


    queue <pii> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    dis[x][y] = 0;
    grid[x][y] = '.';

    // cout << t << '\n';

    while (!Q.empty())
    {
        pii u = Q.front();
        Q.pop();

        // cout << "parent ";
        // cout << u.ff << ' ' << u.ss << ' ';
        // cout << dis[u.ff][u.ss] << '\n';

        lop(0, 4)
        {
            int x = u.ff + dx[i];
            int y = u.ss + dy[i];

            if (valid(x, y) or grid[x][y] == '#' or vis[x][y])
                continue;

            if (grid[x][y] == '.')
            {
                vis[x][y] = 1;
                Q.push({x, y});
                dis[x][y] = dis[u.ff][u.ss] + 1;
            }
            else
            {
                if (grid[x][y] != t)
                    continue;

                return dis[u.ff][u.ss] + 1;
            }
            // cout << x << ' ' << y << ' ' << dis[x][y] << '\n';
        }
    }

    return -1;
}

int main()
{
    int x, test, t = 1;

    cin >> test;

    while (test--)
    {
        cin >> n;
        k = 0;

        lop(0, n)
        {
            lopj(0, n)
            {
                cin >> grid[i][j];

                if (grid[i][j] != '.' and grid[i][j] != '#')
                    k++;
            }
        }

        Case(t++);
        if (k == 1)
        {
            cout << 0 << '\n';
            continue;
        }

        vector <pii> lst;
        for (int p = 0; p < k; p++)
        {
            bool f = 0;
            lop(0, n)
            {
                lopj(0, n)
                {
                    if (grid[i][j] == (char) ('A' + p))
                    {
                        lst.push_back({i, j});

                        f = 1;
                        break;

                    }
                }
                if (f) break;
            }
        }

        int ans = 0;
        lop(0, k - 1)
        {
            // lop(0, n)
            // {
            //     lopj(0, n) cout << grid[i][j];
            //     cout << endl;
            // }
            // cout << endl;

            int u = lst[i].ff, v = lst[i].ss;
            int x = bfs(u, v, 'A' + i + 1);
            if (x == -1)
            {
                ans = -1;
                break;
            }
            // cout << x << '\n';
            ans += x;
        }
        // lop(0, n)
        // {
        //     lopj(0, n) cout << grid[i][j];
        //     cout << endl;
        // }
        // cout << endl;

        if (ans == -1)
            cout << "Impossible\n";
        else
            cout << ans << '\n';
    }

    return 0;
}
