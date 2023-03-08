#include<bits/stdc++.h>

using namespace std;

double L, n, C;

double cal_arc(double h)
{
    double c = L * 0.5;
    double r = (h * 0.5) + ((c * c) / (2 * h));
    double theta = 2 * asin(c / r);

    return r * theta;
}

int main()
{
    int x, test, t = 1;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        cin >> L >> n >> C;

        double s = (1 + (n * C)) * L;

        double l = 0, h = L, m;
        int i = 0;
        while (i++ < 50)
        {
            m = (l + h) * 0.5;

            if (cal_arc(m) > s)
                h = m;
            else
                l = m;
        }

        cout << fixed << setprecision(6) << l << '\n';
    }

    return 0;
}
