#include<bits/stdc++.h>

using namespace std;

struct Point
{
    double x, y;

    bool operator == (const Point &a) const
    {
        return x == a.x && y == a.y;
    }

    bool operator != (const Point &a) const
    {
        return x != a.x || y == a.y;
    }
//
//    bool operator < (const Point &a) const
//    {
//        return x < a.x && y < a.y;
//    }
};

struct Edge
{
    Point u, v;
    float cost;

    bool operator < (const Edge &a) const
    {
        return cost < a.cost;
    }
};

vector <Edge> e;
map <Point, Point> par;

Point findrp(Point a)
{
    return (par[a] == a) ? a : par[a] = findrp(par[a]);
}

float kruskal_mst()
{
    sort(e.begin(), e.end());

    int saiz = e.size();
    float cost = 0;

//    for(int i = 0; i < saiz; i++) {
//        cout << e[i].u << " -> " << e[i].v << " = " << e[i].cost <<'\n';
//        cout << e[i].u << "'s rep = " << par[e[i].u] << '\n';
//        cout << e[i].v << "'s rep = " << par[e[i].v] << '\n';
//    }

    for(int i = 0; i < saiz; i++)
    {
        Point u = findrp(e[i].u), v = findrp(e[i].v);

        if(u != v)
        {
            par[u] = v;

            cost += e[i].cost;
        }
    }

    return cost;
}

float distant(Point a, Point b);

int main()
{
    int test, p;

    cin >> test;
    cin.ignore();
    cin.ignore();

    while(test--)
    {
        e.clear();
        par.clear();

        cin >> p;

        Point point[p];
        Edge line;

        for(int i = 0; i < p; i++) {
            cin >> point[i].x >> point[i].y;
            par[point[i]] = point[i];
        }

        for(int i = 0; i < p - 1; i++) {
            for(int j = i + 1; i < p; i++) {
                line.u = point[i];
                line.v = point[j];
                line.cost = distant(point[i], point[j]);

                e.push_back(line);
            }
        }

        cout << setprecision(2) << kruskal_mst() << '\n';

        if(test > 1)
            cout << '\n';
    }

    return 0;
}

float distant(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) - (a.y - b.y) * (a.y - b.y));
}
