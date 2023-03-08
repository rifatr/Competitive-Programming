#include<stdio.h>
int main()
{
    int a,b;

    scanf("%d %d",&a,&b);
    int box[a+1][b+1];
    int i,j=0;
    for(i=0;i<b;i++)
    {
        box[a][i]=0;
    }
    for(i=0;i<a;i++)
    {
         box[i][b]=0;

        for(j=0;j<b;j++)
        { scanf("%d",&box[i][j]);

        box[a][j]=box[a][j]+box[i][j];
        //printf("%d\n",box[a][j]);
        box[i][b]=box[i][j]+box[i][b];
        }

    }
    box[a][b]=0;
    for(i=0;i<b;i++)
    {
        box[a][b]=box[a][b]+box[a][i];
    }
    for(i=0;i<=a;i++)
    {
        for(j=0;j<=b;j++)
        {
            printf("%d ",box[i][j]);
        }
        printf("\n");
    }
   // printf("\n");
    return 0;
}
