#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, k, x, y;

    cin >> n >> k;

//    x = n % k;
//    y = k - x;

    cout << min(n % k, k - (n % k)) << endl;

    return 0;
}

