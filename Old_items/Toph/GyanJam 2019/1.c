#include<stdio.h>

int main()
{
    int t, s, i, j;
    scanf("%d", &t);

    for(i = 0; i < t; i++) {
        scanf("%d", &s);
        printf("Case %d: Harr", i + 1);
        for(j = 0; j < s; j++) {
            printf("y");
        }
        printf("! Khelbe Hogwarts, Jitbe Hogwarts!\n");
    }

    return 0;
}
