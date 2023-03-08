#include<stdio.h>
#include<math.h>
#define N 100100

int mark[N];
int primes[100000];
int np;

void sieve()
{
    int i, j, limit = sqrt(N * 1.0);

    mark[0] = mark[1] = 1;

    primes[0] = 2;

    for(i = 4; i <= N; i += 2)
        mark[i] = 1;

    for(i = 3; i <= N; i += 2)
    {
        if(mark[i] == 0)
        {
            np++;
            primes[np] = i;

            if(i <= limit)
            {
                for(j = i * i; j <= N; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    sieve();

    //printf("%d %d\n", np, primes[1]);

    int i, j, z;

    for(i = 2; i <= 100000; i++)
    {
        printf("%d:", i);

        if(mark[i] == 0) {
            printf(" %d\n", i);
            continue;
        }

        for(j = 0; ; j++)
        {
            z = primes[j];

            if(z > i / 2)
                break;

            if(i % z == 0)
                printf(" %d", z);
        }

        printf("\n");
    }

    return 0;
}

