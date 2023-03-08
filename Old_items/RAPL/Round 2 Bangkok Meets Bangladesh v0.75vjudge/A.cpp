#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, test;

    ll a[3];

    lop(0, 3) cin >> a[i];

    sort(a, a + 3);

    cout << a[1] << '\n';

    return 0;
}

