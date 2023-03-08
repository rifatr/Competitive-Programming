#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, test;

    cin >> test;

    for(int i = 1; i <= test; i++)
    {
        cin >> a >> b >> c;

        printf("Case %d: ", i);

//        if(a + b <= c || a + c <= b || b + c <= a) {
//            cout << 0 << endl;
//            continue;
//        }

        double s, area;
        s = a + b + c;

        s = s / 2.0;

        area = sqrt(s * (s - a) * (s - b) * (s - c));

        printf("%.10lf\n", area);
    }

    return 0;
}

