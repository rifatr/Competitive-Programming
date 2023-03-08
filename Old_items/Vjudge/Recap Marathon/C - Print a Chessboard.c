#include<stdio.h>
int main()
{
    int w,h,i,j,k,m,n;
    for(i=0; ; i++)
    {
        scanf("%d %d",&h,&w);
        if(h==0&&w==0)
            break;
        for(j=0; j<h; j++)
        {
            for(k=0; k<w; k++)
            {
                if(j%2==0)
                {
                    if(k%2==0)
                        printf("#");
                    else
                        printf(".");
                }
                else if(j!=0)
                {
                    if(k%2==0)
                        printf(".");
                    else
                        printf("#");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}
