#include<stdio.h>

int main()
{
    int t, n, i, j, k;

    scanf("%d", &t);

    int box[t];

    for(i = 0; i < t; i++) {
        scanf("%d", &box[i]);
    }

    for(i = 0; i < t; i++) {

        for(j = 0; j < box[i]; j++) {

            for(k = 0; k < box[i]; k++) {
                printf("*");
            }
            if(j < box[i] - 1)
                printf("\n");
        }
        printf("\n");
        if(i < t - 1)
            printf("\n");
    }

    return 0;
}
