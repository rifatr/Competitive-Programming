#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

struct edge
{
    int u, v, w;

    bool operator < (const edge &B) const
    {
        return w < B.w;
    }
};

const int N = 57;
vector<edge> e;
int rep[N], n, sum;

int findrep(int a)
{
    return rep[a] = rep[a] == a ? a : findrep(rep[a]);
}

void Union(int a, int b)
{
    rep[findrep(b)] = findrep(a);
}

int kruskal()
{
    lop(n + 2) rep[i] = i;

    int cnt = 0, cost = 0, saiz = e.size();
    lop(saiz)
    {
        int u = findrep(e[i].u);
        int v = findrep(e[i].v);

        if (u == v) continue;

        cost += e[i].w;
        cnt++;
        Union(e[i].u, e[i].v);

        if (cnt == n - 1)
            break;
    }

    if (cnt !=  n - 1) return -1;

    return sum - cost;
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        cin >> n;

        int a;
        lop(n) loop(j, 0, n)
        {
            cin >> a;
            sum += a;

            if (!a) continue;

            edge get;
            get.u = i;
            get.v = j;
            get.w = a;
            e.push_back(get);
        }

        sort(e.begin(), e.end());
        cout << kruskal() << '\n';

        e.clear();
        sum = 0;
    }

    return 0;
}