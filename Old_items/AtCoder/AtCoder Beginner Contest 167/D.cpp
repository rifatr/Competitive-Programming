#include<bits/stdc++.h>

#define ll unsigned long long

using namespace std;

int main()
{
    //cout << 727202214173249351 % 6;

    ll n , k;

    cin >> n >> k;

    ll ar[n + 1];

    for(ll i = 1; i <= n; i++)
        cin >> ar[i];

    ll mov = 12;// k % n;

    ll pos = 1;
    for(ll i = 0; i < mov; i++) {
        pos = ar[pos];
        cout << pos << " " << ar[pos] << endl;
    }

    cout << pos << '\n';

    return 0;
}
