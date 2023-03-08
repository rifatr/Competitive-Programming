#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[3];

    cin >> a[0] >> a[1] >> a[2];

    swap(a[0], a[1]);
    swap(a[0], a[2]);

    printf("%d %d %d\n", a[0], a[1], a[2]);

    return 0;
}
