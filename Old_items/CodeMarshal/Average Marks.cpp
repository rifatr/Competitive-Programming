#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, n, test;

    cin >> test;

    for(int i = 1; i <= test; i++)
    {
        cin >> n;

        int num, sum = 0;

        for(int j = 0; j < n; j++) {
            cin >> num;
            sum += num;
        }

        printf("Case %d: ", i);
        cout << sum / n << endl;
    }

    return 0;
}

