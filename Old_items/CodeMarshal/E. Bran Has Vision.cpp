#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ran_rate, i, sum;

    while(scanf("%d", &n) == 1) {
        int ran[6 * n];
        sum = 0;

        for(i = 0; i < 6 * n; i++) {
            cin >> ran[i];
            sum += ran[i];
        }

        ran_rate = sum / n;

        cout << 50 * ran_rate << endl;
    }

    return 0;
}
