#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ll n, x, a, b;
    //string s;

    cin >> a >> b >> n;

    x = n < b ? n : b - 1;

    cout << ((a * x) / b) - (a * (x / b)) << endl;

    return 0;
}


