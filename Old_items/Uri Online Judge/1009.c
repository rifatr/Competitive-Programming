#include<stdio.h>

int main()
{
    char a[100];
    float b, c;
    scanf("%s %f %f", &a, &b, &c);
    printf("TOTAL = R$ %.2f\n", b + (c * .15));
    return 0;
}

