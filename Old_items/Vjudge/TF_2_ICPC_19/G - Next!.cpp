#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;

    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 & c == 0)
            break;
        if(b - a + b == c)
            printf("AP %d\n", b + c - a);
        else
            printf("GP %d\n", b * c / a);
    }

    return 0;
}
