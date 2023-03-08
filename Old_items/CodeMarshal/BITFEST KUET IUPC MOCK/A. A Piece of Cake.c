#include<stdio.h>

int main()
{
    long long int i, j, t, n;

    scanf("%lld", &t);

    for(i = 0; i < t; i++) {
        scanf("%lld", &n);
        printf("0");
        for(j = 1; j <= n; j++)
            printf(" %lld", j);
        printf("\n");
    }
    return 0;
}
