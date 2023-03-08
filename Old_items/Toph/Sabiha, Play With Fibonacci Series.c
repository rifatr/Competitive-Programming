#include<stdio.h>

int main()
{
    int t, i, o = 2, e = 1;
    unsigned long long int n, p3, p1 = 0, p2 = 1;
    scanf("%d", &t);
    //int F[88];

    /*F[0] = 0;
    F[1] = 1;*/

    for(i = 0; i < t; i++)
    {
        scanf("%llu", &n);
        if(n == 0)
            printf("1 0\n");
        else if(n == 1)
            printf("1 2\n");
        else
        {
            p3 = p1 + p2;

            while(p3 < n) {
                p1 = p2;
                p2 = p3;
                p3 = p1 + p2;

                if(p3 % 2 == 0) {
                    e++;
                    //printf("%llu is even\n", p3);
                }
                else {
                    o++;
                   // printf("%llu is odd\n", p3);
                }
            }

            /*for(j = 2; F[j] <= n; j++)
            {
                F[j] = F[j - 1] + F[j - 2];
                if(F[j] % 2 == 0)
                    e++;
                else
                    o++;
            }*/
            printf("%d %d\n", e, o);
        }
    }

    return 0;
}
