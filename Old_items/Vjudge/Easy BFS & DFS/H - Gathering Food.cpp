#include<bit/stdc++.h>

using namespace std;

#define lop(n) for(int i = 0; i < n; i++)
#define lopj(n) for(int j = 0; j < n; j++)
#define pii pair <int, int>
#define ff
#define N 11

char grid[N][N];
bool vis[N][N];
int RC, k;
vector <pii> alpha;

int main()
{
    int test, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> RC;

        lop(RC) lopj(RC)
        {
            cin >> grid[i][j];

            if(isalpha(grid[i][j]))
                alpha.push_back({i, j});
        }
    }
}
