#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll a, b, c;
    string res = "NO\n";

    cin >> a >> b >> c;

    if(c == 0) {
        if(a == b)
            res = "YES\n";
    }

    else if((b > a and c < 0) || (b < a and c > 0))
        res = "NO\n";

    else if((b - a) % c == 0)
            res = "YES\n";

    cout << res;
//main();
    return 0;
}
