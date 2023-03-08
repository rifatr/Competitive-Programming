#include<stdio.h>
#include<string.h>

int main()
{
    int t, j, count;
    int i, l;
    char line[10000];
    scanf("%d\n", &t);

    for(i = 0; i < t; i++)
    {
        scanf("%[^\n]s", line);
        getchar();
        //gets(line);
        count = 0;
        //l = strlen(line);
        //printf("%d\n", l);

        for(j = 0; line[j] != '\0' ; j++) {
            if((line[j] == ' ') && (line[j - 1] != ' '))
                count++;
        }
        printf("%d\n", count + 1);
    }
    return 0;
}
