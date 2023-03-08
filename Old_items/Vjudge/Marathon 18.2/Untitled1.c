#include <stdio.h>
int main()
{
    int x;
    for(;;)
    {
        int sum = 0, h;
        scanf("%d", &x);
        if(x==0)
        {
            break;
        }
        while (x != 0)
        {
            h = x % 10;
            sum       = sum +h;
            x         = x / 10;
        }
        printf("%d\n",sum);
    }
    return 0;
}
