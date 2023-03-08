#include<bits/stdc++.h>
#include<set>

using namespace std;

int main()
{
    int q, n, x, z;
    scanf("%d", &q);
    set <int> s;

    while(q--) {
        scanf("%d %d", &n, &x);
        if(n == 0) {
            s.insert(x);
            printf("%d\n", s.size());
        }
        else if(n == 1) {
            if(s.count(x))
                printf("1\n");
            else
                printf("0\n");
        }
        else {
            s.erase(x);
        }
    }
    return 0;
}
