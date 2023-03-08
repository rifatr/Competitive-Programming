#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int n, m;

    cin >> n >> m;

    ll dorm[n + 1], ltr;
    dorm[0] = 0;

    for(int i = 1; i<= n; i++)
        cin >> dorm[i], dorm[i] += dorm[i - 1];

    for(int i = 1; i<= m; i++)
    {
        cin >> ltr;

        int x = lower_bound(dorm + 1, dorm + n + 1, ltr) - dorm;

        cout << x << ' ' << ltr - dorm[x - 1] << '\n';
    }

    return 0;
}
