#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long i, j, m, n;

    cin >> m >> n;

    printf("YES\n");

    for(i = m; i < n; i +=2)
        printf("%lld %lld\n", i, i + 1);

    return 0;
}
