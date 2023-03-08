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

const int N = 1e4 + 6;
vector<edge> e;
int rep[N], n, m, k;

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

    return cost;
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        cin >> n >> m >> k;

        int a;
        lop(m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (w >= k) continue;

            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }

        sort(e.begin(), e.end());
        int ap = 1, cost = kruskal();

        lop(n + 1) int u = findrep(i);
        sort(rep + 1, rep + 1 + n);
        loop(i, 1, n) if (rep[i] != rep[i + 1]) ap++;

        cout << cost + (ap * k) << ' ' << ap << '\n';

        e.clear();
    }

    return 0;
}
