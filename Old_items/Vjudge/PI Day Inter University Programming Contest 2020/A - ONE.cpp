#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long k, n, p;

    cin >> n >> k;
    p = ceil(n / 2.0);

    if(k <= p)
        cout << 2 * k - 1 << endl;
    else
        cout << 2 * (k - p) << endl;

    return 0;
}
