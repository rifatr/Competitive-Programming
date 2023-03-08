#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[3], test;

    cin >> test;

    for(int i = 1; i <= test; i++)
    {
        cin >> num[0] >> num[1] >> num[2];

        sort(num, num + 3);

        printf("Case %d: ", i);
        cout << num[1] << endl;
    }

    return 0;
}

