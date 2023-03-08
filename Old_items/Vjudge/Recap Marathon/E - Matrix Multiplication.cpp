#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int i, j, k, n, m, l;

    scanf("%lli %lli %lli", &n, &m, &l);

    long long int a[n][m], b[m][l], c[n][l];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%lli", &a[i][j]);
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < l; j++)
            scanf("%lli", &b[i][j]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < l; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < l; j++) {
            printf("%lli", c[i][j]);
            if(j < l - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
