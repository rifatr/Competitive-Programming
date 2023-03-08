#include<stdio.h>
int main ()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int largest = a;

    largest = (b > largest ? b : largest);
    largest = (c > largest ? c : largest);
    printf("%d eh o maior\n", largest);
}

