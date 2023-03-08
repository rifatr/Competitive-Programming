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
        cout << max(a, max(b, c)) << endl;
    }

    return 0;
}
