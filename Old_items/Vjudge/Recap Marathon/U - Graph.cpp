#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, u, v, i, j, x;

    cin >> n;

    bool adjmat[n + 1][n + 1];

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
            adjmat[i][j] = false;
    }

    for(i = 0; i < n; i++)
    {
        cin >> x >> d;
        for(j = 0; j < d; j++)
        {
            cin >> u;
            adjmat[x][u] = true;
        }
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++) {
            cout << adjmat[i][j];
            if(j < n)
                cout << " ";
        }
        cout << endl;
    }
}
