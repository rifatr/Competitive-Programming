#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct edge {
    int u, v, w;

    bool operator<(const edge& p) const
    {
        return w < p.w; //sorting non decreasing or choto theke boro
    }
};

map <int, int> par; //parrent
vector<edge> e; //edges with their cost

int findrep(int r)
{
    return (par[r] == r) ? r : par[r] = findrep(par[r]);
}

ll kruskal_mst(int n)
{
    sort(e.begin(), e.end());

    for (int i = 1; i <= n; i++)
        par[i] = i; //parrenting ownself

    int cnt = 0, s = 0;
    int saiz = e.size();

    for (int i = 0; i < saiz; i++) {
        int u = findrep(e[i].u);
        int v = findrep(e[i].v);

        if (u != v) { //checking this edge is already in the latest graph or not
            par[u] = v; //union

            cnt++; //number of edges of latest graph
            s += e[i].w; //coast of latest graph

            if (cnt == n - 1)
                break;
        }
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        e.push_back({u, v, w});
    }

    cout << kruskal_mst(N) << endl;

    return 0;
}
