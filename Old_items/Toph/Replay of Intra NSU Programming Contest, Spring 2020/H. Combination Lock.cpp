/*
* rifatrraazz
*/


#include<bits/stdc++.h>
#define ll long long
#define M 1000000007

using namespace std;

ll power(ll a, ll b){
     if(b == 0)
        return 1;
     else if(b % 2)
        return a * power(a, b - 1);
     else {
        ll temp = power(a, b / 2);
        return temp * temp;
     }
}

int main()
{
    ll t, n, d, k;

    cin >> t;

    ll caseno = 1;
    while(t--)
    {
        cin >> n;
        ll digit, result = 1;
        for(ll i = 0; i < n; i++)
        {
            cin >> d >> k;

            digit = pow(10, d);
            digit = (digit - 1) / (2 * k + 1) + 1;
            //cout << "10 to the power " << d << " " << digit << endl;
            result *= digit;
            result %= M;
        }

        cout << "Case " << caseno++ << ": " << result << endl;
    }

    return 0;
}

