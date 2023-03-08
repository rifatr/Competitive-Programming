#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b, c) for(int j = a; j < b; j += i)
#define scan(a) scanf("%d", &a)
#define N 1000006

int divv[N + 1];
ll sum[N + 1];

void divc()
{
    lop(1, N)
        lopj(i, N, i)
            divv[j]++;
}

int main()
{
    divc();

    int n, q, x;

    scan(n);

    int a[n + 1];

    lop(1, n + 1) cin >> a[i];

    lop(1, n + 1)
        sum[divv[a[i]]] += a[i];

    lop(1, N)
        sum[i] += sum[i - 1];

    scan(q);

    lop(0, q)
    {
        scan(x);
        printf("%lld\n", sum[x]);
    }

    if(q == 0)
        printf("\n");

    return 0;
}
