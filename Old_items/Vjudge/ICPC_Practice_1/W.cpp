#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        ll n, k;
        cin >> n >> k;

        vector <ll> up, dwn;

        loop(i, n - k + 1, n + 1) up.push_back(i * i);
        lop(k)
        {
            ll x = i + 1;

            for (ll j = 2; j * j <= x; j++)
            {
                while (x % j == 0)
                {
                    x /= j;
                    dwn.push_back(j);
                }
            }

            if (x > 1) dwn.push_back(x);
        }

        int saiz1 = up.size(), saiz2 = dwn.size();
        lop(saiz2) loop(j, 0, saiz1)
        {
            if (up[j] % dwn[i] == 0)
            {
                up[j] /= dwn[i];
                dwn[i] = 1;
                break;
            }
        }

        ll ans = 1LL;
        lop(saiz1) ans *= up[i];

        cout << ans << '\n';
    }

    return 0;
}
