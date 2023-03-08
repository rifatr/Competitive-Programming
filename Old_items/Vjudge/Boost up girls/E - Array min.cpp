#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, t, n, q, inp, p, o;
    vector <int> v1, v2;

    scanf("%d", &t);

    for(int j = 1; j <= t; j++)
    {
        scanf("%d %d", &n, &q);
        for(i = 0; i < n; i++) {
            cin >> inp;
            v1.push_back(inp);
        }
        printf("Case %d:\n", j);
        for(i = 0; i < q; i++)
        {
            v2 = v1;
            scanf("%d %d", &p, &o);
            p--; o--;
            //printf("values = %d %d\n", v2[p], v2[o]);
            sort(v2.begin() + p, v2.begin() + o);
            printf("values = %d %d\n", v2[p], v2[o]);
            printf("%d\n", v2[o]);
            v2.clear();
        }
        v1.clear();
    }

    return 0;
}
