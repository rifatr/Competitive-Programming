#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

map <int, int> seg;

int main()
{
    int x, test, t = 1;;

    scanf("%d", &test);

    while (test--)
    {
        printf("Case %d:\n", t++);

        int n, q, a;
        scanf("%d %d", &n, &q);

        seg[-1] = 0;
        lop(n) scanf("%d", &a), seg[a]++;
        auto it = seg.begin();
        auto it2 = it; it2++;

        for (; it2 != seg.end(); it++, it2++)
            it2 -> second += it -> second;

        while (q--)
        {
            int l, r;
            scanf("%d %d", &l, &r);

            it = seg.upper_bound(r); it--;
            it2 = seg.lower_bound(l); it2--;

            printf("%d\n", it -> second - it2 -> second);
        }

        seg.clear();
    }

    return 0;
}
