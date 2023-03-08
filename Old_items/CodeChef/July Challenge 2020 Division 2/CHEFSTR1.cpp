#include<bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)

int absl(int a, int b)
{
    if(a < b) swap(a, b);

    return a - b;
}

int main()
{
    int tt;

    sc(tt);

    while(tt--)
    {
        int n, a, b = 0;
        long long s = 0;

        sc(n);

        while(n--)
        {
            sc(a);

            if(b)
                s += absl(a, b) - 1;

            b = a;
        }

        printf("%lld\n", s);
    }

    return 0;
}
