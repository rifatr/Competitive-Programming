#include<stdio.h>

int main()
{
    int a, b, e, d;
    float c, f, dif;
    scanf("%d %d %f %d %d %f", &a, &b, &c, &d, &e, &f);
    dif = (c * b) + (e * f);
    printf("VALOR A PAGAR: R$ %.2f\n", dif);
    return 0;
}




