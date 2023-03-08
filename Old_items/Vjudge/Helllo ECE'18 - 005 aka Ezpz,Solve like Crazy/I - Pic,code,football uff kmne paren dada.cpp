#include<bits/stdc++.h>

using namespace std;

int main()
{
    double h, l, ans;

    scanf("%lf %lf", &h, &l);

    ans = (((l / 1.0) * (l / 1.0)) - ((h / 1.0) * (h / 1.0))) / (2 * (h / 1.0));

    printf("%.10lf\n", ans);

    return 0;
}
