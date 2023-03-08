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

double circle(double r, double ang)
{
    return (ang / 2.0) * sq(r);
}
int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        double r1, r2, r3;
        cin >> r1 >> r2 >> r3;

        double c = r1 + r3, b = r2 + r3, a = r2 + r1;
        double ang1 = angle(a, c, b);
        double ang2 = angle(a, b, c);
        double ang3 = angle(c, b, a);

        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));

        area -= circle(r1, ang1) + circle(r2, ang2) + circle(r3, ang3);

        cout << fixed << setprecision(6) << area << '\n';
    }

    return 0;
}