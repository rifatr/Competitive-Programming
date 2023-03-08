#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "

int n, m;
char grid[21][21];

int dfs(int x, int y)
{
    if(x < 0 or y < 0 or x == m or y == n or grid[x][y] == '#')
        return 0;

    grid[x][y] = '#';

    return dfs(x - 1, y) + dfs(x, y - 1) + dfs(x + 1, y) + dfs(x, y + 1) + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, test, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> n >> m;

        lop(0, m) lopj(0, n) cin >> grid[i][j];

        Case(t++);

        lop(0, m) lopj(0, n)
        {
            if(grid[i][j] == '@')
                cout << dfs(i, j) << '\n';
        }
    }

    return 0;
}

