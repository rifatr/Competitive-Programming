#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll a, b, c, k, sum = 0, temp;

    cin >> a >> b >> c >> k;

    temp = min(a, k);

    sum = temp;

    k -= temp;

    if(k <= 0) {
        cout << sum << endl;
        return 0;
    }

    temp = min(b, k);

    k -= temp;

    if(k <= 0) {
        cout << sum << endl;
        return 0;
    }

    sum -= k;

    cout << sum << endl;

    return 0;
}
