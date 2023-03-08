#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, l, j, k;
    char line[1000], reverse_line[1000];

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf(" %[^\n]s", line);
        l = strlen(line);
        for(j = 0; j < l; j++) {
            if((line[j] >= 'A' && line[j] <= 'Z') || (line[j] >= 'a' && line[j] <= 'z'))
                line[j] = line[j] + 3;
        }
        for(j = 0, k = l - 1; j < l; j++, k--){
            reverse_line[j] = line[k];
        }
        reverse_line[j] = '\0';
        //if(l % 2 == 0)
            k = l / 2;
       // else
         //   k = l / 2 - 1;
        for(j = k; j < l; j++) {
            reverse_line[j] = reverse_line[j] - 1;
        }
        //printf("%s", line);
        printf("%s", reverse_line);
        printf("\n");
    }

    return 0;
}
