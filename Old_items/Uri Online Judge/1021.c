#include<stdio.h>
int main ()
{
    double n, hundred, fifty, twenty,ten, five, two, one;
    scanf("%ld", &n);

    printf("NOTAS:\n");
    hundred = n / 100;
    printf("%d nota(s) de R$ 100,00\n", hundred);
    fifty = (n - hundred * 100) / 50;
    printf("%d nota(s) de R$ 50,00\n", fifty);
    twenty = (n - hundred * 100 - fifty * 50) / 20;
    printf("%d nota(s) de R$ 20,00\n", twenty);
    ten = (n - hundred * 100 - fifty * 50 - twenty * 20) / 10;
    printf("%d nota(s) de R$ 10,00\n", ten);
    five = (n - hundred * 100 - fifty * 50 - twenty * 20 - ten * 10) / 5;
    printf("%d nota(s) de R$ 5,00\n", five );
    two = (n - hundred * 100 - fifty * 50 - twenty * 20 - ten * 10 - five * 5) / 2;
    printf("%d nota(s) de R$ 2,00\n", two);
    one = (n - hundred * 100 - fifty * 50 - twenty * 20 - ten  * 10 - five * 5 - two * 2) / 1;
    printf("%d nota(s) de R$ 1,00\n", one);

    printf("MOEDAS:\n");

}

