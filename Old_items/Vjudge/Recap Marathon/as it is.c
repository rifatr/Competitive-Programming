#include<stdio.h>
int main()
{
    int a;
    int i;
    for(i=1;;i++)
   {
        scanf("%d",&a);
        if(a==0)
        {
            break;
        }
    printf("Case %d: %d\n",i,a);

   }
}
