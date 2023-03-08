#include<bits/stdc++.h>

using namespace std;

double sq(double a)
{
    return a * a;
}

double angle(double a, double b, double c)
{
    return acos((sq(a) + sq(b) - sq(c)) / (2 * a * b));
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        double a, b;
        char c;
        cin >> a >> c >> b;

        double r = sqrt(sq(a) + sq(b)) / 2;
        double ang = angle(r, r, b);
        double s = r * ang;

        double x = 200 / (a + s);
        double l = a * x, w = b * x;

        cout << fixed << setprecision(6) << l << ' ' << w << '\n';
    }

    return 0;
}