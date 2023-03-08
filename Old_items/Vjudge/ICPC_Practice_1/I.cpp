#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
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
    return 0.5 * (((a.x * (b.y - c.y)) + (b.x * (c.y - a.y))) + (c.x * (a.y - b.y)));
}

bool check(Point p)
{
    ll l = 1, h = n - 1, m;

    while (h - l > 1)
    {
        m = (l + h) / 2;

        // printf("%lld %lld %lld %lld\n", l, h, m, tri_area(point[0], point[m], p));

        if (tri_area(point[0], point[m], p) < 0)
            h = m;
        else
            l = m;
    }

    if (tri_area(point[0], point[l], p) < 0)
    {
        // printf("l = %lld area = %lld\n", l, tri_area(point[0], point[l], p));
        return 0;
    }
    if (tri_area(point[h], point[0], p) < 0)
    {
        // printf("h = %lld area = %lld\n", h, tri_area(point[h], point[0], p));
        return 0;
    }
    if (tri_area(point[l], point[h], p) < 0)
    {
        // printf("l = %lld h = %lld area = %lld\n", l, h, tri_area(point[l], point[h], p));
        return 0;
    }

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
