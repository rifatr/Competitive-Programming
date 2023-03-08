#include<stdio.h>


int main()
{
    int x,y,z, i, j, k;
    scanf("%d %d %d",&x, &y, &z);
    int a[x], b[y], c[z];
    for(i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < y; i++)
    {
        scanf("%d", &b[i]);
    }
    for(i = 0; i < z; i++)
    {
        scanf("%d", &c[i]);
    }
    int p[x];
    for(i = 0; i < x; i++)
    {
        int v = a[i], cb = 0, cc = 0;
        for(j = 0; j < y; j++)
        {
            if(b[j] < v)
                cb++;
        }
        for(k = 0; k < z; k++)
        {
            if(c[k] > v)
                cc++;
        }
        p[i] = 1+cb+cc;
    }
    int max = p[0];
    for(i = 0; i < x; i++) {
        if(p[i] > max)
                max = p[i];
    }

    printf("%d\n", max);

    return 0;

}
