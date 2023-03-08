#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tt;

    cin >> tt;

    for(int i = 1; i <= tt; i++)
    {
        int a[3];

        cin >> a[0] >> a[1] >> a[2];

        sort(a, a + 3);

        printf("Case %d: ", i);
        cout << a[1] << endl;
    }

    return 0;
}
