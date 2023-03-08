#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll threen(ll x)
{
    ll j = x;
    ll counter = 0;

    while(1)
    {
        counter++;

        if(j == 1)
            break;
        if(j % 2 == 0)
            j /= 2;
        else
            j = 3 * j + 1;
    }

    return counter;
}

void OJ()
{
    freopen("K input.txt", "r", stdin);
    freopen("K output.txt", "w", stdout);
}

int main()
{
    //OJ();

    ll i, n, a, b, s, t;
    vector <ll> chain;

    while(scanf("%lld %lld", &a, &b) == 2)
    {
        s = min(a, b);
        t = max(a, b);
        for(i = s; i <= t; i++)
        {
            ll j = i;
            ll counter = 0;

            while(1)
            {
                counter++;

                if(j == 1)
                    break;
                if(j % 2 == 0)
                    j /= 2;
                else
                    j = 3 * j + 1;
            }
            chain.push_back(counter);
        }

        sort(chain.begin(), chain.end(), greater <ll> ());

        printf("%lld %lld %lld\n", a, b, chain[0]);

        chain.clear();
    }

    return 0;
}
