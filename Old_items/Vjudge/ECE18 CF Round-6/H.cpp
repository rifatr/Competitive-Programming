#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;

    cin >> n >> x >> y;

    n /= 2;

    if((x == n and y == n) or (x == n and y == n + 1) or (x == n + 1 and y == n) or (x == n + 1 and y == n + 1))
        cout << "NO\n";
    else
        cout << "YES\n";


    return 0;
}

