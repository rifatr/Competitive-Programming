#include<stdio.h>
#include<string.h>

int main()
{
    int i,j, l;
    char a[100],b[100];
    scanf("%s",a);
    l = strlen(a);
    for(i= 0, j = l-1; i < l; i++, j-- ) {
        b[i] = a[j];
    }
    b[i]='\0';
    printf("%s",b);
}
