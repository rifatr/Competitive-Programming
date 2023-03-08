#include<bits/stdc++.h>

#define ll long long
#define lop(n) for(ll i = 0; i < n; i++)

using namespace std;

int main()
{
    ll t, n, m;

    cin >> t;

    lop(t) {
        cin >> n >> m;

//        double anglend = (180.0 * (n - 2)) / n;
//        double anglemd = (180.0 * (m - 2)) / m;
//        ll anglenl = (180 * (n - 2)) / n;
//        ll angleml = (180 * (m - 2)) / m;

        if(n % m == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
