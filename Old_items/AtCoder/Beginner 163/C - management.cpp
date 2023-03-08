#include<bits/stdc++.h>

#define pi 2 * acos(0.0)

using namespace std;

int main()
{
    int i, n, m, x;

    //map <int, int> p;

    cin >> n;

    int p[n + 1];

    for(i = 0; i <= n; i++)
        p[i] = 0;

    for(i = 1; i < n; i++)
    {
        cin >> x;
        p[x]++;
    }

    for(i = 1; i <= n; i++)
        cout << p[i] << endl;

    return 0;
}
