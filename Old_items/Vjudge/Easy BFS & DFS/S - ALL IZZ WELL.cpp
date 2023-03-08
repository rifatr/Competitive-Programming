#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "

#define N 105

char grid[N][N];
int n, R, C;
bool vis[N][N], f;
string s = "ALLIZZWELL";

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

void dfs(int x, int y, int i);

int main()
{
    int test, t = 1, x, y;

    cin >> test;

    while(test--)
    {
        cin >> R >> C;

        lop(0, R) lopj(0, C) cin >> grid[i][j];

        f = 0;

        lop(0, R)
        {
            lopj(0, C)
            {
                if(grid[i][j] == 'A')
                    dfs(i, j, 0);

                if(f)
                    break;
            }

            if(f)
                break;
        }

        lop(0, R) lopj(0, C) vis[i][j] = 0;

        cout << (f == 1 ? "YES" : "NO") << '\n';
    }

    return 0;
}

void dfs(int x, int y, int i)
{
    if(i == 9) {
        f = 1;
        return;
    }

    //cout << x << ' ' << y << ' ' << i << '\n';

    if(grid[x][y] == s[i])
    {
        vis[x][y] = 1;
        i++;

        lopj(0, 8)
        {
            int xx = x + dx[j];
            int yy = y + dy[j];

            if(xx < 0 or yy < 0 or xx >= R or yy >= C or vis[xx][yy])
                continue;

            //cout << xx << ' ' << yy << ' ' << i << '\n';

            if(grid[xx][yy] == s[i])
                dfs(xx, yy, i);
        }
        vis[x][y] = 0;
    }
}
