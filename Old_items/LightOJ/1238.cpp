#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "
#define ff first
#define ss second
#define pii pair <int, int>

int R, C, f;
char grid[21][21];
int visited[21][21], hfora[21][21], hforb[21][21], hforc[21][21];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};


void bfs(pii s);

int main()
{
    //freopen("D in.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> R >> C;

        lop(0, R) lopj(0, C) cin >> grid[i][j];

        Case(t++);

        pii a, b, c, h;

        lop(0, R) lopj(0, C)
        {
            if(grid[i][j] == 'a')
            {
                a.ff = i;
                a.ss = j;
            }

            else if(grid[i][j] == 'b')
            {
                b.ff = i;
                b.ss = j;
            }

            else if(grid[i][j] == 'c')
            {
                c.ff = i;
                c.ss = j;
            }

            else if(grid[i][j] == 'h')
            {
                h.ff = i;
                h.ss = j;
            }
        }

        f = 0;
        bfs(a);
        f++;
        bfs(b);
        f++;
        bfs(c);

        cout << max(hfora[h.ff][h.ss], max(hforb[h.ff][h.ss], hforc[h.ff][h.ss])) << '\n';
    }

    return 0;
}

void bfs(pii s)
{
    lop(0, R) lopj(0, C) visited[i][j] = 0;

    queue <pii> Q;
    visited[s.ff][s.ss] = 1;
    Q.push(s);
    if(f == 0)
        hfora[s.ff][s.ss] = 0;
    else if(f == 1)
        hforb[s.ff][s.ss] = 0;
    else
        hforc[s.ff][s.ss] = 0;

    while(!Q.empty())
    {
        pii u = Q.front();
        Q.pop();

        lop(0, 4)
        {
            int vr = u.ff + dr[i];
            int vc = u.ss + dc[i];

            if(vr < 0 or vc < 0 or vr >= R or vc >= C or grid[vr][vc] == '#' or grid[vr][vc] == 'm' or visited[vr][vc])
                continue;

            visited[vr][vc] = 1;
            Q.push({vr, vc});
            if(f == 0)
                hfora[vr][vc] = hfora[u.ff][u.ss] + 1;
            else if(f == 1)
                hforb[vr][vc] = hforb[u.ff][u.ss] + 1;
            else
                hforc[vr][vc] = hforc[u.ff][u.ss] + 1;

        }
    }
}
