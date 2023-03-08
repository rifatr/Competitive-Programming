#include<stdio.h>

int main()
{
    int t,n[3],m[3] ;
    int i,j,k,l;
    scanf("%d",&t);
    for(i=1;i<=t && t<=3;i++)
    {
        l=0;
        scanf("%d%d",&n[i],&m[i]);
        for(j=1;j<=m[i] && m[i]<=100000;j++ )
        {
          k=n[i]%j;
          l=l+k;
        }
        printf("case %d=%d\n",i,l);
    }

    return 0;
}
