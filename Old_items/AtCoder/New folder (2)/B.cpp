
#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ll n, i, j, a, b, k, d;
    string s;
    //set <pair <ll, ll> > s;

    cin >> n >> k;
    bool X[n] ={0};

    while(k--)
    {
        cin >> d;
        while(d--)
        {
            cin >> a;
            X[--a] = 1;
        }
    }



    cout << count(X, X + n, 0) << '\n';

    return 0;
}

