#include<bits/stdc++.h>

using namespace std;

#define PII pair<double, double>
#define F first
#define S second

struct Edge
{
    PII u, v;
    double cost;

    bool operator < (const Edge &a) const
    {
        return cost < a.cost;
    }
};

vector <Edge> e;
map <PII, PII> par;

PII findrp(PII a)
{
    return (par[a] == a) ? a : par[a] = findrp(par[a]);
}

double kruskal_mst()
{
    sort(e.begin(), e.end());

    int saiz = e.size();
    double cost = 0;

//    for(int i = 0; i < saiz; i++) {
//        cout << e[i].u.F << " -> " << e[i].v.F << " = " << e[i].cost <<'\n';
//        cout << e[i].u.F << "'s rep = " << par[e[i].u].F << '\n';
//        cout << e[i].v.F << "'s rep = " << par[e[i].v].F << '\n';
//    }

    for(int i = 0; i < saiz; i++)
    {
        PII u = findrp(e[i].u), v = findrp(e[i].v);

        if(u != v)
        {
            par[u] = v;

            cost += e[i].cost;
        }
    }

    return cost;
}

double distant(PII a, PII b);
void OJ();

int main()
{
    //OJ();

    int test, p;

    cin >> test;
    cin.ignore();
    cin.ignore();

    while(test--)
    {
        e.clear();
        par.clear();

        cin >> p;
        cin.ignore();

        PII point[p];
        Edge line;

        for(int i = 0; i < p; i++) {
            cin >> point[i].F >> point[i].S;
            par[point[i]] = point[i];
        }

        for(int i = 0; i < p - 1; i++) {
            for(int j = i + 1; j < p; j++) {
                line.u = point[i];
                line.v = point[j];
                line.cost = distant(point[i], point[j]);

//                cout << "u = " << line.u.F << " " << line.u.S << '\n';
//                cout << "v = " << line.v.F << " " << line.v.S << '\n';
//                cout << "cost = " << line.cost << '\n';

                e.push_back(line);
            }
        }

        printf("%.2lf\n", kruskal_mst());
        if(test >= 1)
            cout << '\n';
    }

    return 0;
}

double distant(PII a, PII b)
{
//    cout << "line x = " << (a.F - b.F) * (a.F - b.F) << '\n';
//    cout << "line y = " << (a.S - b.S) * (a.S - b.S) << '\n';

    return sqrt(((a.F - b.F) * (a.F - b.F)) + ((a.S - b.S) * (a.S - b.S)));
}

void OJ()
{
    freopen("p10034 input.txt", "r", stdin);
}

