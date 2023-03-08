#include<stdio.h>
int main()
{
    double x, y;
    scanf("%lf %lf", &x, &y);
    double one, two, three, four, five;

    if(x == 1)
    {
        one =  y * 4.00;
        printf("Total: R$ %.2lf\n", one);
    }
    else if(x == 2)
    {
        two = y * 4.50;
        printf("Total: R$ %.2lf\n", two);
    }
    else if(x == 3)
    {
        three = y * 5.00;
        printf("Total: R$ %.2lf\n", three);
    }
    else if(x == 4)
    {
        four = y * 2.00;
        printf("Total: R$ %.2lf\n", four);
    }
    else if(x == 5)
    {
        five = y * 1.50;
        printf("Total: R$ %.2lf\n", five);
    }
}

