#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a, sum = 0;

    for(int i = 0; i < 12; i++)
    {
        scanf("%lf", &a);

        sum += a;
    }

    printf("$%.2lf\n", (double) (sum / 12));

    return 0;
}
