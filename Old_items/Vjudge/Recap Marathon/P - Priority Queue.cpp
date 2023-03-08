#include<bits/stdc++.h>
#include<queue>

using namespace std;

int main()
{
    long long int i, n, q, t, num, x, l;
    scanf("%lld %lld", &num, &q);
    priority_queue <long long int> pq[num];

    for(i = 0; i < q; i++) {
        scanf("%lld", &n);
        if(n == 0) {
            scanf("%lld %lld", &t, &x);
            pq[t].push(x);
        }
        else if(n == 1) {
            scanf("%lld", &t);
           l = pq[t].size();
           if(l !=0)
                printf("%lld\n", pq[t].top());

        }
        else {
            scanf("%lld", &t);
            l = pq[t].size();
            if(l !=0)
                pq[t].pop();
        }
    }
    return 0;
}
