#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, s, d;
    scanf("%d", &t);
    int i, j;

    for(i = 0; i < t; i++ )
    {
        scanf("\n %d", &s);
        int sum = 0;
        for(j = 0; j < s; j++){
            scanf("%d", &d);
            if(d >= 0)
                sum += d;
        }
        printf("Case %d: %d\n", i + 1, sum);
    }
    return 0;
}
