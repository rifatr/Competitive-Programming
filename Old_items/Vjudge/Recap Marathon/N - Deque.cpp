#include<bits/stdc++.h>
#include<deque>

using namespace std;

int main()
{
    int q, i, x, p, d;

    deque <int> v;

    scanf("%d", &q);

    for(i = 0; i < q; i++) {
        scanf("%d", &p);
        if(p == 0) {
            scanf("%d %d", &d, &x);
            if(d == 0)
                v.push_front(x);
            else
                v.push_back(x);
        }
        else if(p == 1) {
            scanf("%d", &x);
            printf("%d\n", v[x]);
        }
        else {
            scanf("%d", &d);
            if(d == 0)
                v.pop_front();
            else
                v.pop_back();
        }
    }
    return 0;
}
