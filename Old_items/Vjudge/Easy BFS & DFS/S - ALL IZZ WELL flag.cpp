
#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "

#define N 105

char grid[N][N];
int n, R, C;
bool flag[10], vis[N][N];
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

		int c;

        lop(0, R)
        {
        	lopj(0, C)
        	{
            	if(grid[i][j] == 'A'){
            		lop(0, 10) flag[i] = 0;
            		dfs(i, j, 0);
            	}

            	c = count(flag, flag + 10, 0);

            	if(!c) break;
        	}

        	if(!c) break;
        }
//
//        lop(0, 10) cout << flag[i];

        cout << (c == 0 ? "YES" : "NO") << '\n';

        lop(0, 10) flag[i] = 0;
        lop(0, R) lopj(0, C) vis[i][j] = 0;
    }

    return 0;
}

void dfs(int x, int y, int i)
{
    if(grid[x][y] == s[i])
    {
        flag[i] = 1;
        vis[x][y] = 1;
        i++;

        lopj(0, 8)
        {
            int xx = x + dx[j];
            int yy = y + dy[j];

            if(xx < 0 or yy < 0 or xx >= R or yy >= C or i > 9 or vis[xx][yy])
                continue;

            if(grid[xx][yy] == s[i])
                dfs(xx, yy, i);
        }
        vis[x][y] = 0;
    }
}
