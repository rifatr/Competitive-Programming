#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, q, i, j, sl, num, sum;

    scanf("%d", &t);
    while(t--)
    {
        int score[8];
        for(i = 0; i < 8; i++)
        {
            score[i] = 0;
        }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &sl, &num);
            if(sl < 9 && score[sl - 1] < num)
                score[sl - 1] = num;
        }
        sum = 0;
        for(i = 0; i < 8; i++)
            sum += score[i];

        printf("%d\n", sum);
    }

    return 0;
}
