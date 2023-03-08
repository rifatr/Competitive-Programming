#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define yes cout << "y\n"
#define no cout << "n\n"

struct Point
{
    ll x, y;
};

const int N = 1e5 + 9;
Point point[N];
int n;

ll tri_area(Point a, Point b, Point c)
{
    return ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y))) + (c.x * (a.y - b.y));
}

bool check(Point p)
{
    ll l = 1, h = n - 1, m;

    while (h - l > 1)
    {
        m = (l + h) / 2;

        if (tri_area(point[0], point[m], p) < 0)
            h = m;
        else
            l = m;
    }

    if (tri_area(point[0], point[l], p) < 0)
        return 0;
    if (tri_area(point[h], point[0], p) < 0)
        return 0;
    if (tri_area(point[l], point[h], p) < 0)
        return 0;

    return 1;
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ":\n";
        cin >> n;

        lop(n) cin >> point[i].x >> point[i].y;

        int q;
        cin >> q;
        while (q--)
        {
            Point p;
            cin >> p.x >> p.y;

            if (check(p))
                yes;
            else
                no;
        }
    }

    return 0;
}