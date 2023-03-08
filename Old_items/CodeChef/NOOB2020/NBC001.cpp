#include<bits/stdc++.h>

using namespace std;

#define double long double

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        if(a + b > c and a + c  > b and b + c > a)
        {
            cout << "YES ";
            double s = (a + b + c) / 2;

            double area = sqrt(s * (s - a) * (s - b) * (s - c));
            cout << fixed << setprecision(5) << area << '\n';
        }

        else
            cout << "NO\n";
    }

    return 0;
}
