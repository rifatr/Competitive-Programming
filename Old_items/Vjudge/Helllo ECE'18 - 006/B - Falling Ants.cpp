#include<bits/stdc++.h>

#define scan(a) scanf("%d", &a)
#define lop(n) for(int i = 0; i < n; i++)
#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main()
{
    int n, l, h, w;

    while(scan(n) and n)
    {
        pair <int, int> hv[n];

        lop(n)
        {
            scan(l); scan(w); scan(h);
            hv[i] = mp(h, l * w * h);
        }

        sort(hv, hv + n);

        printf("%d\n", hv[n - 1].ss);
    }

    return 0;
}
