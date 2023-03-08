#include<stdio.h>
int main ()
{
    float a, b;
    double s;
    scanf("%f %f", &a, &b);
    s = (a * b) / 12;
    printf("%.3lf", s);
}
