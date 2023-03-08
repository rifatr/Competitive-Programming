#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, x, y, z, count;
    cin >> t;

    while(t--)
    {
        cin >> x >> y >> z;
        count = ((x * y * z) / ((x * y) + (x * z) + (y * z)));
        cout << count << endl;
    }

    return 0;
}
