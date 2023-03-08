#include<stdio.h>

int main()
{
    int a, b, i, j, p;
    scanf("%d %d", &a, &b);
    p = b - a + 1;
    int chain[p];

    for(i = 0; i < p; i++)
        chain[i] = 0;

    for(i = a; i <= b; i++) {

        for(j = i; ;) {
            chain[i]++;
            if(j == 1)
                break;
            if(j % 2 == 0)
                j = j / 2;
            else
                j = 3 * j + 1;
        }
    }
    int maxim = chain[0];

    for(i = 0; i < p; i++)
        maxim = maxim > chain[i] ? maxim : chain[i];

    printf("%d %d %d\n", a, b, maxim);

    return 0;
}

