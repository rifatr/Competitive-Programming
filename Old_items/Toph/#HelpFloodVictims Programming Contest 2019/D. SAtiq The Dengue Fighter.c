#include<stdio.h>
#include<string.h>


int main()
{
    char s1[101];

    scanf("%s", s1);

    if(s1 == "Fever")
        printf("Go to hospital right now.\n");
    else
        printf("Go to hospital.\n");

    return 0;
}

