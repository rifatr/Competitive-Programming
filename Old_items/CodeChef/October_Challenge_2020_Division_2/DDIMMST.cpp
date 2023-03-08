#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct edge {
    int u, v, w;

    bool operator<(const edge& p) const
    {
        return w > p.w; //sorting non increasing or boro theke choto
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

        if (u != v) {
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, D;

    cin >> N >> D;
    int point[N][D];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < D; j++)
            cin >> point[i][j];

    edge get;

    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            ll w = 0;

            if(D == 1)
                w = abs(point[i][0] - point[j][0]); 

            else if(D == 2)
                w = abs(point[i][0] - point[j][0]) + abs(point[i][1] - point[j][1]);

            else if(D == 3)
                w = abs(point[i][0] - point[j][0]) + abs(point[i][1] - point[j][1]) + abs(point[i][2] - point[j][2]);

            else if(D == 4)
                w = abs(point[i][0] - point[j][0]) + abs(point[i][1] - point[j][1]) + abs(point[i][2] - point[j][2]) + abs(point[i][3] - point[j][3]);

            else 
                w = abs(point[i][0] - point[j][0]) + abs(point[i][1] - point[j][1]) + abs(point[i][2] - point[j][2]) + abs(point[i][3] - point[j][3]) + abs(point[i][4] - point[j][4]);

            get.u = i;
            get.v = j;
            get.w = w;
            e.push_back(get);

        }
    }

    cout << kruskal_mst(N) << endl;

    return 0;
}
