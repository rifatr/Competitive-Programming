#include <bits/stdc++.h>

using namespace std;

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    /*int t;
    while(y != 0)
    {
        t = y;
        y = x % y;
        x = t;
    }

    return x;*/

    if(x % y == 0)
        return y;
    return(y, x % y);
}

int main()
{
    unsigned long long a, b, lcmm;
    int test, i, gcdd;

    scanf("%d", &test);

    for(i = 0; i < test; i++)
    {
        scanf("%llu %llu", &a, &b);

        gcdd = gcd(a, b);
        lcmm = a * b / gcdd;

        cout << gcdd << " " << lcmm << endl;

        if(gcdd + lcmm == a + b)
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}
