#include<stdio.h>
#include<math.h>
int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy;
    double s;
    int l,k;
    scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
    dx=cx-(bx-ax);
    dy=cy-(by-ay);
    printf("%d %d\n",dx,dy);
   // l=sqrt(((cx-ax)*(cx-ax))+((cy-ay)*(cy-ay)));
    //k=sqrt(((dx-bx)*(dx-bx))+((dy-by)*(dy-by)));
    s=(sqrt(((cx-ax)*(cx-ax))+((cy-ay)*(cy-ay)))*sqrt(((dx-bx)*(dx-bx))+((dy-by)*(dy-by))))/2;
    printf("%lf\n",s);
    return 0;
}
