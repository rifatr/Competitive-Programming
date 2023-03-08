#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, i, f = 1;
    scanf("%d %d", &a, &b);

    int c[a];

    for(i = 0; i < a; i++) {
        scanf("%d", &c[i]);
    }

    for(i = 0; i < a; i++) {
        if(c[i] >= b) {
            f = 0;
        }
        else {
            f = 1;
            break;
        }
    }

    if(a * b != 60)
        printf("NO\n");
    else if(f == 0)
       printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
