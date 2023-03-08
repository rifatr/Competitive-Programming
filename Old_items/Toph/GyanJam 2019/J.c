#include<stdio.h>
#include<math.h>

int main()
{
    unsigned long long n,m,s, b;
    int i,  sum = 0;
    scanf("%llu %llu", &n, &m);
    if(n == m)
    {
        for(i = 1; i * i < n; i++)
        {
            if(n % i == 0)
                sum += i;
        }
        for(i = n/i; i <= n; i++)
        {
            if(n % i == 0)
                sum += i;
        }
    }
    else if(n < m)
    {
        s = n;
        b = m;
        for(i = 1; i * i < n; i++)
        {
            if((n % i == 0) && (m % i == 0))
                sum += i;
        }
        for(i = n / i; i <= n; i++)
        {
            if((n % i == 0) && (m % i == 0))
                sum += i;
        }
    }
    else
    {
        s = m;
        b = n;
        for(i = 1; i * i < n; i++)
        {
            if((n % i == 0) && (m % i == 0))
                sum += i;
        }
        for(i = n/i; i <= n; i++)
        {
            if((n % i == 0) && (m % i == 0))
                sum += i;
        }
    }
    printf("%d\n", sum);

    return 0;
}
