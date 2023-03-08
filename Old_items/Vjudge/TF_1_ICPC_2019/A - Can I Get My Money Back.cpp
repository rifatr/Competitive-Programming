#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N, n, m, o, x, y, i, j, flag;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%d %d", &n, &m);
        for(j = 0; j < n; j++)
            scanf("%d", &o);
        flag = 0;
        for(j = 0; j < m; j++)
        {
            scanf("%d %d", &x, &y);
            if(x + 1 != y)
                flag = 1;
        }
        if(flag == 1)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    }
    return 0;
}
