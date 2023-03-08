#include<stdio.h>

int main()
{
    int t,n,i,j,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        int a[n];
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }

        printf("%d\n",n-1);
    }
    return 0;
}

