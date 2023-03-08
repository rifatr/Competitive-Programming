#include<bits/stdc++.h>

#define pi 2 * acos(0.0)

using namespace std;

int main()
{
    int n, m, x, sum = 0;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> x;
        sum += x;
    }

    if(sum > n)
        cout << -1 << endl;
    else
        cout << n - sum << endl;

    return 0;
}

