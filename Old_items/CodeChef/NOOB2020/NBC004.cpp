#include<bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 1e9+7;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        if(n == 1)
        {
            cout << 1 << '\n';
            continue;
        }

        n--;

        ll a = ((n % N) * ((n + 1) % N)) % N;
        ll b = ((n % N) * ((n + 1) % N)) % N;
        b = ((b % N) * ((n + 2) % N) ) % N;

        cout << (1LL + a + b) % N << '\n';
    }

    return 0;
}
