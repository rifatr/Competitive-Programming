#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    long long n, q, t, x, i, j, k, siz;

    scanf("%lld %lld", &n, &q);

    vector <long long> v[n];

    for(i = 0; i < q; i++) {
        scanf("%lld", &n);
        if(n == 0) {
            scanf("%lld %lld", &t, &x);
            v[t].push_back(x);
        }
        else if(n == 1) {
            scanf("%lld", &t);
            siz = v[t].size();
            for(j = 0; j < siz; j++) {
                printf("%lld", v[t].at(j));
                if(j < siz - 1)
                    printf(" ");
            }
            printf("\n");
        }
        else {
            scanf("%lld", &t);
            v[t].clear();
        }
    }
    return 0;
}
