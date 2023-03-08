#include<bits/stdc++.h>

using namespace std;

const int N = 1002;
string a, b;
int x, y;
int lcs[N][N];

int main()
{
    int tt;

    cin >> tt;

    while(tt--)
    {
        cin >> a >> b;

        x = a.size(), y = b.size();

        for(int i = 0; i < x; i++)
            lcs[i][0] = 0;
        for(int i = 0; i < y; i++)
            lcs[0][i] = 0;

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
    }

    return 0;
}
