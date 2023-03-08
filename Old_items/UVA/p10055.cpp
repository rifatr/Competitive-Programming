#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

int main()
{
    long long a, b;

    while(scanf("%lld %lld", &a, &b) == 2) {
        long long ans = abs(a-b);
        printf("%lld\n", ans);
    }

    return 0;
}
