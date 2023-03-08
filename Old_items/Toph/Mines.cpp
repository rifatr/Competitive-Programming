#include<bits/stdc++.h>

using namespace std;

char grid[10][10];
int r, c;
int dr[] = {1,-1,0,0,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1,1,-1};

char cnt(int x, int y);

int main()
{
    cin >> r >> c;

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> grid[i][j];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << cnt(i, j);
        cout << endl;
    }

    return 0;
}

char cnt(int x, int y)
{
    if(grid[x][y] == '*')
        return '*';

    int p = 0;

    for(int i = 0; i < 8; i++) {
        int xx = x + dr[i], yy = y + dc[i];

        if(xx < 0 or xx >=  r or yy < 0 or yy >= c)
            continue;

        if(grid[xx][yy] == '*')
            p++;
    }

    return p ? '0' + p : '.';
}
