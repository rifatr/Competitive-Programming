#include<iostream>
#include<math.h>

const double pi = acos(-1.0);

using namespace std;

int main()
{
    int n;
    double x, y;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;

        double r = sqrt((x * x) + y * y);

        double area = pi * r * r / 2.0;

        int res = (int) ceil(area / 50.0);

        cout << "Property " << i << ": This property will begin eroding in year ";
        cout << res << ".\n";
    }

    cout << "END OF OUTPUT.\n";

    return 0;
}
