#include<bits/stdc++.h>

#define ll long long
#define lop(n) for(int i = 0; i < n; i++)
#define lop1(n) for(int i = 1; i <= n; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 999999999999

using namespace std;

struct Edge
{
    string u, v;
    int w;

    bool operator < (const Edge &b) const
    {
        return w > b.w;
    }
};

vector <Edge> e;
map <string, string> par;

string findrep(string u)
{
    return par[u] == u ? u : par[u] = findrep(par[u]);
}

void Union(string u, string v)
{
    par[findrep(u)] = findrep(v);
}

int kruskal_mst(string s, string d)
{
    sort(e.begin(), e.end());

    int saiz = e.size();
    int maxw = 9999999;

//    lop(saiz) {
//        cout << e[i].u << " -> " << e[i].v << " = " << e[i].w <<'\n';
//        cout << e[i].u << "'s rep = " << par[e[i].u] << '\n';
//        cout << e[i].v << "'s rep = " << par[e[i].v] << '\n';
//    }

    lop(saiz)
    {
        if(findrep(e[i].u) != findrep(e[i].v)) {
            Union(e[i].u, e[i].v);

            maxw = min(maxw, e[i].w);
        }
        if(findrep(s) == findrep(d))
            return maxw;
    }
}

int main()
{
    int n, r, wt, i = 0;
    string ct1, ct2;

    while(scanf("%d %d", &n, &r) and n|r)
    {
        i++;
        e.clear();
        par.clear();

        Edge road;

        lop(r)
        {
            cin >> ct1 >> ct2 >> wt;

            road.u = ct1;
            road.v = ct2;
            road.w = wt;

            e.push_back(road);

            par[ct1] = ct1;
            par[ct2] = ct2;
        }

        cin >>  ct1 >> ct2;

        cout << "Scenario #" << i << '\n';
        cout << kruskal_mst(ct1, ct2) << " tons" << '\n' << '\n';
    }

    return 0;
}

