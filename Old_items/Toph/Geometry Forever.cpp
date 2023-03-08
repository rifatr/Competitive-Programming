#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    int x = abs(a - b);

    cout << --a + b - x << endl;

    return 0;
}
