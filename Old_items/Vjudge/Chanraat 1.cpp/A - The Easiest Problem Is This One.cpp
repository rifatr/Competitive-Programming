#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, n, sum1, sum2;

    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        sum1 = 0;
        int x = n;
        while (x != 0)
        {
            sum1 = sum1 + x % 10;
            x = x / 10;
        }
       // cout << "sum1 = " << sum1 << endl;

        for(i = 11; ; i++)
        {
            x = n * i;
            sum2 = 0;
            while (x != 0)
            {
                sum2 = sum2 + x % 10;
                x = x / 10;
            }
            //cout << "sum2 = " << sum2 << endl;

            if(sum1 == sum2)
                break;
        }
        printf("%d\n", i);
    }

    return 0;
}
