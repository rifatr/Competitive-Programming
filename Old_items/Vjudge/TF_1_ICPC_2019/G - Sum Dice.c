#include<stdio.h>

int main()
{
    int i, n, m, small, big;

    scanf("%d %d", &n, &m);

    if(n > m) {
        big = n;
        small = m;
    }
    else if (m > n) {
        big = m;
        small = n;
    }

    else{
        big = n;
        small = m;
    }

    for(i = small; i <= big; i++)
        printf("%d\n", i + 1);
    return 0;
}
