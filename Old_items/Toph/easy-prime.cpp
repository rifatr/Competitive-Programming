#include<bits/stdc++.h>
#define MAX 10000020

using namespace std;

bool mark[MAX + 2];
int n, ara[MAX + 2], a[MAX + 2];

void sieve()
{
    int i, j, l = sqrt(MAX * 1.0);

    mark[1] = mark[0] = true;

    for (i = 4; i <= MAX; i += 2)
        mark[i] = true;

    for (i = 3; i <= l; i += 2) {
        if (mark[i] == false) {
            for (j = i * i; j <= MAX; j += i * 2)
                mark[j] = true;
        }
    }
}

void edit(int x, int ind)
{
    while (ind <= n)
    {
        ara[ind] += x;

        ind += ind & -ind;
    }
}

int sum(int ind)
{
    int s = 0;

    while (ind)
    {
        s += ara[ind];

        ind -= ind & -ind;
    }

    return s;
}

int main()
{
    sieve();

    int q, x, c, d, i;

    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        edit(!mark[a[i]], i);
    }

    cin >> q;

    while (q--)
    {
        cin >> x >> c >> d;

        if (x == 1)
            cout << sum(d) - sum(c - 1) << endl;

        else
        {
            if (mark[a[c]] != mark[d])
            {
                if (mark[a[c]])
                    edit(1, c);
                else
                    edit(-1, c);

                a[c] = d;
            }
        }
    }

    return 0;
}
