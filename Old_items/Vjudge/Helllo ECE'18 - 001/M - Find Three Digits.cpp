#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int a, b, c, n, fib[46], i;

    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i < 46; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cin >> n;

    if(n == 0) {
        printf("0 0 0\n");
        return 0;
    }

    if(n == 1) {
        printf("0 0 1\n");
        return 0;
    }

    if(n == 2) {
        printf("0 1 1\n");
        return 0;
    }

    for(i = 0; i < 46; i++) {
        if(fib[i] == n)
            break;
    }

    printf("%d %d %d\n", fib[i - 4], fib[i - 3], fib[i - 1]);
//main();
    return 0;
}
