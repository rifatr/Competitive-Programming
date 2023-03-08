#include<stdio.h>
int main()
{
    float a, b, p;
    scanf("%f %f", &a, &b);
    p = (a*3.5 + b*7.5) / (3.5+7.5);
    printf("MEDIA = %.5f\n", p);
    return 0;
}

