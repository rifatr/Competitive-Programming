#include<bits/stdc++.h>
#define ull unsigned long long

using namespace std;

//ll mult_mod(vector <ll> n)
//{
//    ll l = n.size();
//
//    if(l == 1)
//        return n[l - 1] % 1000000009;
//
//    ll x = n[l - 1];
//    n.pop_back();
//
//    ll y = mult_mod(n);
//
//    x = ((x % 1000000009) * (y % 1000000009)) % 1000000009;
//
//    return x;
//}

int main()
{
    ull t, n, i, inp, res;
    //vector <ll> mult;

    cin >> t;

    while(t--)
    {
        cin >> n;

        res = 1;
        for(i = 0; i < n; i++)
        {
            cin >> inp;
            //mult.push_back(inp % 1000000009);
            res = ((res % 1000000007) * (inp % 1000000007)) % 1000000007;
        }

        cout << res << endl;
    }

    return 0;
}
