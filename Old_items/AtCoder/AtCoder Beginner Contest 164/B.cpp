#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    int x = ceil(c / (b * 1.0));
    int y = ceil(a / (d * 1.0));

    //cout << x << y;

    x <= y ? cout << "yes\n" : cout << "no\n";

    return 0;
}

