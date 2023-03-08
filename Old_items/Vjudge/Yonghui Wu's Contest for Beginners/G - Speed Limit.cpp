#include<iostream>

using namespace std;

int main()
{
    int t, i, n, d, dis, time1, time2;
    int num[20], counter[100];

    while(scanf("%d", &t) and t != -1)
    {
        time1 = 0;
        dis = 0;
        for(i = 0; i < t; i++)
        {
            scanf("%d %d", &d, &time2);

            dis += d * (time2 - time1);
            time1 = time2;
        }

        printf("%d miles\n", dis);
    }

    return 0;
}

