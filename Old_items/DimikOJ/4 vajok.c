#include<stdio.h>

int main()
{
    int t, n, i, j;

    scanf("%d", &t);

    for(i = 1; i <= t; i++) {
        scanf("%d", &n);
        printf("Case %d:", i);

        for(j = 1; j <= n / 2; j++) {
            if(n % j == 0)
                printf(" %d", j);
        }

        printf(" %d\n", n);
    }

    return 0;
}
