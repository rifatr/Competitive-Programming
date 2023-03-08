#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, l, r, i, j;
    scanf("%d %d", &n, &q);
    int bulb[n];
    for(i = 0; i < n; i++)
        bulb[i] = 0;

    for(i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        for(j = l - 1; j < r ; j++) {
            if(bulb[j] == 0)
                bulb[j] = 1;
            else
                bulb[j] = 0;
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d", bulb[i]);
        if(i < n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
