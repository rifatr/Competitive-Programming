#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(ll i = a; i < b; i++)
#define lopj(a, b) for(ll j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    ll n;

    cin >> n;

    ll c = 0;

    lop(1, n + 1) lopj(i, n + 1)
    {
        ll k = (i ^ j) ^ 0LL;

        //cout << i << " " << j << " " << k << '\n';

        if(k and k >= j and i + j > k and k <= n) {c++;
         //cout << c << endl;
         }
    }

    cout << c << '\n';

    return 0;
}

