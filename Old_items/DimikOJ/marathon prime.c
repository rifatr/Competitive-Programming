#include<stdio.h>

int main()
{
    unsigned long long t, n[10], i, j,k,l,m[10];
    scanf("%llu",&t);
    for(i=0; i<t && t<=10; i++)
    {
        m[i]=1;
        scanf("%d",&n[i]);
        for(j=2; j<n[i] && n[i]<1000000000000; j++)
        {
            l=n[i]%j;
            if(l==0)
            {
                m[i]=0;
                break;
            }
        }
    }
    for(k=0; k<t; k++)
    {
        if(m[k]==0)
        {
            printf("%llu not prime\n",n[k]);
        }
        else
        {
            printf("%llu prime\n",n[k]);
        }
    }
        return 0;
    }
