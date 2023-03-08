#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)

const int N = 1e5 + 6;
int ara[N], n, q;

int sum(int l, int r)
{
    int s = 0;
    while (l <= r)
        s += ara[l], l++;

    return s;
}

int main()
{
    int x, test, t = 1, cmd, u, v;

    scan(test);

    while (test--)
    {
        printf("Case %d:\n", t++);

        scan(n); scan(q);
        lop(n)
        {
            cin >> ara[i];
        }

        while (q--)
        {
            scan(cmd);

            if (cmd == 1)
            {
                scan(x);

                print(ara[x]);
                ara[x] = 0;
            }

            else if (cmd == 2)
            {
                scan(x); scan(v);

                ara[x] += v;
            }

            else
            {
                scan(u); scan(v);

                print(sum(u, v));
            }
        }

        memset(ara, 0, sizeof ara);

    }

    return 0;
}
