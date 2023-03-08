#include<stdio.h>
#include<string.h>
int main()
{
    int a,b;
    int s;int i,j;
    for(s=0;;s++)
    {
         scanf("%d %d",&a,&b);
         if(a==0&&b==0)
         {
             break;
         }

    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            if((i+j)%2==0)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
    }

}
