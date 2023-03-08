#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll s, p;
    cin >> s >> p;

    for (ll i = 1; i * i <= p; i++)
    {
        if (p % i == 0)
        {
            ll k = p / i;
            if (k + i == s)
            {
                yes;
                return 0;
            }
        }
    }

    no;
    return 0;
}
