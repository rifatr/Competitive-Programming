#include<stdio.h>

int main()
{
    int i, j, d = 1000;

    for(i = 0; i < 200; i++) {
        for(j = 5; j > 0; j--) {
            printf("%d\t", d);
            d--;
        }
        printf("\n");
    }
}
