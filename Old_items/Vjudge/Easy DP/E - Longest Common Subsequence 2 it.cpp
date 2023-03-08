#include<bits/stdc++.h>

using namespace std;

const int N = 2004;
int a[N], b[N];
int x, y;
int lcs[N][N];

int main()
{

    cin >> x;
    for(int i = 0; i < x; i++)
        cin >> a[i];

    cin >> y;
    for(int j = 0; j < y; j++)
        cin >> b[j];

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            if(a[i] == b[j])
                lcs[i + 1][j + 1] = 1 + lcs[i][j];

            else
                lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
        }
    }

    cout << lcs[x][y] << '\n';

    int i = x, j = y, path[lcs[x][y]], p = lcs[x][y];

    while(i > 0 and j > 0)
    {
        if(lcs[i][j] == lcs[i - 1][j])
            i--;

        else if(lcs[i][j] == lcs[i][j - 1])
            j--;

        else
            path[--p] = a[--i], j--;
    }

    for(int i = 0; i < lcs[x][y]; i++)
        cout << path[i] << ' ';

    return 0;
}
