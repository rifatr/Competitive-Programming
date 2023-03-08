#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll trail0(ll n);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll l, r;

//    int a = 10, b = 100;
//    ll p = trail0(a), x = 1;
//    for(int i = a; i <= b; i++) {
//        ll n = trail0(i);
//        if(n != p) {
//            p = n;
//            x++;
//        }
//        cout << i << "->" << n << '\t';
//    }
//
//    cout << endl << x << endl;

    while (cin >> l >> r and (l + r))
    {
        cout << (r / 5) - (l / 5) + 1 << '\n';
    }

    return 0;

}


//ll trail0(ll n)
//{
//    ll c = 0, x = 5;
//
//    while(x <= n)
//    {
//        c += (n / x);
//        x *= 5;
//    }
//
//    return c;
//}
