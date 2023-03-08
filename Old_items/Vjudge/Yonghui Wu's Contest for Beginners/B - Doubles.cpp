#include<iostream>

using namespace std;

int main()
{
    int t, i, n, c;
    int num[20], counter[100];

    while(scanf("%d", &t) and t != -1)
    {
        if(t == 0) continue;

        for(i = 0; i < 100; i++) counter[i] = 0;

        num[0] = t;
        counter[t]++;
        n = 1;

        while(scanf("%d", &t) and t != 0) {
            num[n++] = t;
            counter[t]++;
        }

        c = 0;

        for(i = 0; i < n; i++)
        {
            if(num[i] % 2) continue;

            if(counter[num[i] / 2]) c++;
        }

        printf("%d\n", c);
    }

    return 0;
}
