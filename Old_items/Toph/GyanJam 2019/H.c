#include<stdio.h>
#include<string.h>

char revi(char a[1000])
{
    int i,j, l;
    char b[1000];
    l = strlen(a);
    for(i= 0, j = l-1; i < l; i++, j-- ) {
        b[i] = a[j];
    }
    b[i]='\0';
    return b[1000];
}
int  main()
{
    int i, l;
    char s1[1000], s2[1000];
    scanf("%s",s1);
    //scanf("%s",s2);
    l = strlen(s1);

    s2[1000]=revi(s1);
    printf("%s",s2);

}
