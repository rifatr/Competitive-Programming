#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, f = 1;

    cin >> n;

    for(i = n; i > 1; i--)
        f = (f * i) % 10000;

    cout << f << endl;

    return 0;
}
