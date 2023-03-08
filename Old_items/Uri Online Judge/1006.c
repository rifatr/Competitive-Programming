#include<stdio.h>
int main()
{
    float a, b, c, v;
    scanf("%f %f %f", &a, &b, &c);
    v = (a*2 + b*3 + c*5) / (2+3+5);
    printf("MEDIA = %.1f\n", v);
    return 0;
}


