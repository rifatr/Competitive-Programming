#include<bits/stdc++.h>

#define ll long long
#define lop(n) for(int i = 1; i <= n; i++)
#define lop0(n) for(int i = 0; i < n; i++)
#define N 10009

using namespace std;

struct Edge
{
    int u, v;
    ll w;

    bool operator < (const Edge &a) const
    {
        return w < a.w;
    }
};

vector <Edge> e;
int par[N + 1];

int findrep(int a)
{
    return par[a] == a ? a : par[a] = findrep(par[a]);
}

ll kruskal_mst(int n)
{
    sort(e.begin(), e.end());

    lop(n)
    {
        par[i] = i;
    }

    int saiz = e.size(), eg = 0;
    ll cost = 0;

    lop0(saiz)
    {
        int u = findrep(e[i].u);
        int v = findrep(e[i].v);

        if(u != v)
        {
            par[u] = v;

            cost += e[i].w;
            eg++;
        }

        if(eg == n - 1)
            break;
    }

    return cost;
}

int main()
{
    int n, m, n1, n2;
    ll wt;
    Edge edge;

    scanf("%d %d", &n, &m);

    lop(m)
    {
        scanf("%d %d %lld", &edge.u, &edge.v, &edge.w);
        e.push_back(edge);
    }

    printf("%lld\n", kruskal_mst(n));

    return 0;
}
