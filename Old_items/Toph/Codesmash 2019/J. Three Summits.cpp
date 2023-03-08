#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k, i, j, l, sum, counter = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        counter = 0;
        for(i = 1; i <= n; i++) {
            for(j = 1; j < i; j++) {
                for(l = 1; l < j; l++) {
                    if(i + j + l <= k)
                        counter++;
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}
