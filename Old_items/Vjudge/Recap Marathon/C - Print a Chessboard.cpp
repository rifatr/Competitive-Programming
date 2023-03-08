#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i = 0, h, w;

    while(1)
    {
        scanf("%d %d", &h, &w);

        if(h == 0 && w == 0)
            break;

        for(int j = 1; j <= h; j++)
        {
            if(j % 2 != 0)
            {
                for(int k = 1; k <= w; k++)
                {
                    if(k % 2 != 0)
                        printf("#");
                    else
                        printf(".");
                }
                printf("\n");
            }
            else
            {
                for(int m = 1; m <= w; m++)
                {
                    if(m % 2 != 0)
                        printf(".");
                    else
                        printf("#");
                }
                printf("\n");
            }
        }
        printf("\n");
        i++;
    }

    return 0;
}
