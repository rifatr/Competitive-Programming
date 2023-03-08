#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ll n, t, x = 100, i, j;
    string s;

    cin >> n;

    for(i = 1; ; i++)
    {
        x += (x * 0.01);
        if(x >= n)
            break;
    }

    cout << i << endl;

    return 0;
}

