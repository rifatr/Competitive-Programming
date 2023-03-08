#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

const double pi = acos(-1.0);

double sq(double a)
{
    return a * a;
}

double volume(double r1, double r2, double h)
{
    return (pi * h * (sq(r1) + sq(r2) + (r1 * r2))) / 3;
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        double r1, r2, h, p;
        cin >> r1 >> r2 >> h >> p;

        double increased_r = (r1 - r2) * p / h;
        double mid_r = r2 + increased_r;

        cout << fixed << setprecision(6) << volume(mid_r, r2, p) << '\n';
    }

    return 0;
}
