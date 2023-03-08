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

const int N = 107;
vector<edge> e;
int rep[N], n;

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

        if (cnt == n)
            break;
    }

    return cost;
}

int main()
{
    int test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        cin >> n;
        edge ed;

        while (1)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (!u and !v and !w)
                break;

            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }

        sort(e.begin(), e.end());
        int cost = kruskal();
        sort(e.rbegin(), e.rend());
        cost += kruskal();

        if (cost % 2 == 0)
            cout << cost / 2 << '\n';
        else
            cout << cost << "/" << 2 << '\n';

        e.clear();
    }

    return 0;
}