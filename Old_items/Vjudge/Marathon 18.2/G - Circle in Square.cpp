#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    double r;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", i, ((4 - 2 * acos(0.0)) * r * r));
    } //rrraazz
    return 0;
}
