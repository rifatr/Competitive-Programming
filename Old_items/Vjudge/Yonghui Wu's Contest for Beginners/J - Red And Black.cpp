#include<iostream>
#include<string>

using namespace std;

string line[21];
int r, c;

int dfs(int x, int y);

int main()
{
    while(cin >> c >> r and r and c)
    {
        for(int i = 0; i < r; i++)
            cin >> line[i];

        bool f = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)
                if(line[i][j] == '@') {
                    cout << dfs(i, j) << '\n';
                    f = 1;
                    break;
                }
            if(f == 1)
                break;
        }

    }
}

int dfs(int x, int y)
{
    if(x < 0 or y < 0 or x >= r or y >= c or line[x][y] == '#')
        return 0;

    line[x][y] = '#';

    return dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1) + 1;
}
