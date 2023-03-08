#include<stdio.h>

int main()
{
    int t, i, num, last_digit, first_digit;

    scanf("%d", &t);

    for(i = 0; i < t; i++) {
        scanf("%d", &num);
        last_digit = num % 10;
        first_digit = num / 10000;
        printf("Sum = %d\n", last_digit + first_digit);
    }

    return 0;
}
