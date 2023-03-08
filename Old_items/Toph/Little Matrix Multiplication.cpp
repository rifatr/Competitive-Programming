#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[2][2][2];

    for(int k = 0; k < 2; k++)
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                cin >> a[k][i][j];

    cout << (a[0][0][0] * a[1][0][0]) + (a[0][0][1] * a[1][1][0]) << ' ';
    cout << (a[0][0][0] * a[1][0][1]) + (a[0][0][1] * a[1][1][1]) << '\n';
    cout << (a[0][1][0] * a[1][0][0]) + (a[0][1][1] * a[1][1][0]) << ' ';
    cout << (a[0][1][0] * a[1][0][1]) + (a[0][1][1] * a[1][1][1]) << '\n';

    return 0;
}
