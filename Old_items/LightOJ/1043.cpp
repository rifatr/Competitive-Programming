#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, i;
    double ab, ac, bc, ad, de, ratio1, ratio2 = 1;

    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &ratio1);

        double r = ratio1 / (ratio1 + ratio2);

        printf("Case %d: %.8lf\n", i, ab * sqrt(r));
    }

    return 0;
}
