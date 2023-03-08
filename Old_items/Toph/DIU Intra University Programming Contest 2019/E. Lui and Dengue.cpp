#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test, query, a, d, n, i, j, k, sum;

    scanf("%d", &test);

    for(i = 0; i < test; i++) {
        scanf("%d", &query);
        for(j = 0; j < query; j++) {
            sum = 0;
            scanf("%d %d %d", &a, &d, &n);
            for(k = 0; k < n; k++) {
                sum += a;
                a += d;
            }
            printf("%d\n", sum);
        }
    }

    return 0;
}
