#include<stdio.h>
#include<string.h>

int main()
{
    char digit[101];
    int t, l, i;
    scanf("%d", &t);

    for(i = 0; i < t; i++) {
        scanf("%s", digit);
        l = strlen(digit);
        if(digit[l - 1] % 2 == 0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }

    return 0;
}
