#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define scan(x) scanf("%d", &x)
#define scac(x) scanf(" %c", &x)
#define print(x) printf("%d\n", x)

const int N = 1e5 + 6;
int ara[N], n, q;
char s[N];

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
    int x, test, t = 1, u, v;
    char cmd;

    scan(test);

    while (test--)
    {
        printf("Case %d:\n", t++);

        scanf(" %s", s);
        n = strlen(s);
        // loop(i, 1, n + 1) cout << i << ' ';
        // cout << '\n';
        /*lop(n)
        {
            edit(s[i] - '0', i + 1);
            // loop(i, 1, n + 1) cout << ara[i] << ' ';
            // cout << '\n';
        }*/
        // cout << '\n';

        scan(q);
        while (q--)
        {
            scac(cmd);

            if (cmd == 'I')
            {
                scan(u); scan(v);

                edit(1, u);
                edit(-1, v + 1);
                // loop(i, 1, n + 1) cout << ara[i] << ' ';
                // cout << '\n';
            }
            else
            {
                scan(u);
                // cout << u << ' ' << sum(u) << '\t';
                int k = sum(u) % 2;

                k == 0 ? print(s[u - 1] - 48) : print(49 - s[u - 1]);
            }
        }

        memset(ara, 0, sizeof ara);
    }

    return 0;
}
