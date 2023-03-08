#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long total_angle, n, test;

    cin >> test;

    for(long long i = 1; i <= test; i++)
    {
        cin >> total_angle;

        printf("Case %d: ", i);

        if(total_angle % 180 != 0) {
            cout << "Impossible\n";
            continue;
        }

        n = (total_angle / 180) + 2;

        cout << n << " " << total_angle / n << endl;
    }

    return 0;
}

