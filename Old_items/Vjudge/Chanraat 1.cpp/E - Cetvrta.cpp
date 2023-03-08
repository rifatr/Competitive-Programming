#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, x[3], y[3], fx = 0;

    for(i = 0; i < 3; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    if(x[0] != x[1] && x[0] != x[2])
        printf("%d ", x[0]);
    else if(x[1] != x[0] && x[1] != x[2])
        printf("%d ", x[1]);
    else
        printf("%d ", x[2]);

    if(y[0] != y[1] && y[0] != y[2])
        printf("%d\n", y[0]);
    else if(y[1] != y[0] && y[1] != y[2])
        printf("%d\n", y[1]);
    else
        printf("%d\n", y[2]);

    return 0;
}
