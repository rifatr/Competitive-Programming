#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)

const int N = 1e5 + 6;
int ara[N], n, q;

void edit(int x, int ind)
{
    while (ind <= n)
    {
        ara[ind] += x;

        ind += (ind & -ind);
    }
}

int sum(int ind)
{
    int s = 0;
    while (ind)
    {
        s += ara[ind];

        ind -= (ind & -ind);
    }

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
            scan(x);
            edit(x, i + 1);
        }

        while (q--)
        {
            scan(cmd);

            if (cmd == 1)
            {
                scan(x); x++;

                int ans = sum(x) - sum(x - 1);
                edit(-ans, x);

                print(ans);
            }

            else if (cmd == 2)
            {
                scan(x); scan(v); x++;

                edit(v, x);
            }

            else
            {
                scan(u); scan(v); u++, v++;

                print(sum(v) - sum(u - 1));
            }

            // lop(n + 1) cout << ara[i] << ' ';
            // cout << '\n';
        }

        memset(ara, 0, sizeof ara);

    }

    return 0;
}
