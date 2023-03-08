#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define lop(a, b) for(ll i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

vector <int> digit;

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

ll todeci(ll x, ll y)
{
    ll i = 0;
    ll p = 0;

    while(x)
    {
        ll m = x % 10;
        p += power(y, i) * m;
        x /= 10;
        i++;
        digit.push_back(m);
    }

    return p;
}

int mind(ll x)
{
    ll m = 10;

    while(x)
    {
        m = min(m, x % 10);
        x /= 10;
    }

    return m;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    ll n, test, pos;

    cin >> test;

    while(test--)
    {
        cin >> n >> pos;

        if(n == 0LL and pos == 1LL)
        {
            cout << 2 << '\n';
            continue;
        }

        bool f = 0;

        ll ff = mind(n);
        if(ff < 2)
            ff = 2;

        lop(ff, 11LL)
        {
            ll pp = todeci(n, i);

            bool z = 0;
            int saiz = digit.size();
            lopj(0, saiz)
                if(digit[j] == i)
                    z = 1;

            digit.clear();

            if(z)
                continue;

            if(pp == pos - 1) {
                cout << i << '\n';
                f = 1;
                break;
            }
        }

        if(!f)
        cout << -1 << '\n';
    }

    return 0;
}

